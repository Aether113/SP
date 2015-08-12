#ifndef DATAMGR_H_
#define DATAMGR_H_

#include <time.h>

extern int list_errno;

/*
 * definition of error codes
 * */

#define LIST_NO_ERROR 0
#define LIST_MEMORY_ERROR 1 // error due to mem alloc failure
#define LIST_EMPTY_ERROR 2  //error due to an operation that can't be executed on an empty list
#define LIST_INVALID_ERROR 3 //error due to a list operation applied on a NULL list

#define MAP_FILE "room_sensor.map"
#define SENSOR_FILE "sensor_data"

#define SET_MIN_TEMP 18.0
#define SET_MAX_TEMP 25.0

typedef struct element element_t; //element_t is a stuct containing room id, sensor id, running_avg and timestamp last_modified
typedef element_t* element_ptr_t;

typedef struct list list_t; // list_t is a struct containing at least a head pointer to the start of the list;
typedef list_t *list_ptr_t;

typedef struct list_node list_node_t;
typedef list_node_t *list_node_ptr_t;

typedef struct running_avg running_avg_t;
typedef running_avg_t * running_avg_ptr_t;

list_ptr_t list_create 	( // callback functions
			  /*void (*element_copy)(element_ptr_t *dest_element, element_ptr_t src_element),
			  void (*element_free)(element_ptr_t *element),
			  int (*element_compare)(element_ptr_t x, element_ptr_t y),
			  void (*element_print)(element_ptr_t element)*/
			);
// Returns a pointer to a newly-allocated list.
// Returns NULL if memory allocation failed and list_errno is set to LIST_MEMORY_ERROR

void list_free( list_ptr_t* list );
// Every list node and node element of the list needs to be deleted (free memory)
// The list itself also needs to be deleted (free all memory) and set to NULL

int list_size( list_ptr_t list );
// Returns the number of elements in 'list'.

list_ptr_t list_insert_at_index( list_ptr_t list, element_ptr_t element, int index);
// Inserts a new list node containing 'element' in 'list' at position 'index'  and returns a pointer to the new list.
// Remark: the first list node has index 0.
// If 'index' is 0 or negative, the list node is inserted at the start of 'list'.
// If 'index' is bigger than the number of elements in 'list', the list node is inserted at the end of 'list'.
// Returns NULL if memory allocation failed and list_errno is set to LIST_MEMORY_ERROR

list_ptr_t list_remove_at_index( list_ptr_t list, int index);
// Removes the list node at index 'index' from 'list'. NO free() is called on the element pointer of the list node.
// If 'index' is 0 or negative, the first list node is removed.
// If 'index' is bigger than the number of elements in 'list', the last list node is removed.
// If the list is empty, return list and list_errno is set to LIST_EMPTY_ERROR (to see the difference with removing the last element from a list)

list_ptr_t list_free_at_index( list_ptr_t list, int index);
// Deletes the list node at index 'index' in 'list'.
// A free() is called on the element pointer of the list node to free any dynamic memory allocated to the element pointer.
// If 'index' is 0 or negative, the first list node is deleted.
// If 'index' is bigger than the number of elements in 'list', the last list node is deleted.
// If the list is empty, return list and list_errno is set to LIST_EMPTY_ERROR (to see the difference with freeing the last element from a list)

list_node_ptr_t list_get_reference_at_index( list_ptr_t list, int index );
// Returns a reference to the list node with index 'index' in 'list'.
// If 'index' is 0 or negative, a reference to the first list node is returned.
// If 'index' is bigger than the number of list nodes in 'list', a reference to the last list node is returned.
// If the list is empty, NULL is returned.

element_ptr_t list_get_element_at_index( list_ptr_t list, int index );
// Returns the list element contained in the list node with index 'index' in 'list'.
// If 'index' is 0 or negative, the element of the first list node is returned.
// If 'index' is bigger than the number of elements in 'list', the element of the last list node is returned.
// If the list is empty, NULL is returned.

int list_get_index_of_element( list_ptr_t list, element_ptr_t element );
// Returns an index to the first list node in 'list' containing 'element'.
// If 'element' is not found in 'list', -1 is returned.

void list_print( list_ptr_t list );
// for testing purposes: print the entire list on screen

void read_room_map(list_ptr_t list);
//reads the room_sensor.map file and generates a list

void print_sensor_data();
//prints all the sensor data (in ascii) from the sensor data file

void parse_sensor_data();
//updates running_avg and last_modified in the list structure

int update_sensor_node(list_ptr_t list, unsigned int sensor_id, float temp, time_t last_modified);
//finds the correct sensor id and updates its running_avg temperature.
//if running_avg is to low or to high, an error message is send to stderr
//return 0 for succes, sth else for fail

#endif  //LIST_H_
