#include "list_ops.h"

// constructs a new list
list_t *new_list(size_t length, list_element_t elements[])
{
    // Allocate memory for the list
    list_t *list = (list_t *)malloc(sizeof(list_t) + length * sizeof(list_element_t));

    if (list == NULL)
    {
        // handle error if malloc fails
        return NULL;
    }

    // Set the length of the list
    list->length = length;

    // Copy the elements into the list
    for (size_t i = 0; i < length; i++)
    {
        list->elements[i] = elements[i];
    }

    return list;
}

// append entries to a list and return the new list
list_t *append_list(list_t *list1, list_t *list2)
{
    // Calculate the total length of the new list
    size_t total_length = list1->length + list2->length;

    // Allocate memory for the new list
    list_t *new_list = (list_t *)malloc(sizeof(list_t) + total_length * sizeof(list_element_t));

    if (new_list == NULL)
    {
        // handle error if malloc fails
        return NULL;
    }

    // Set the length of the new list
    new_list->length = total_length;

    // Copy the elements of list1 into the new list
    for (size_t i = 0; i < list1->length; i++)
    {
        new_list->elements[i] = list1->elements[i];
    }

    // Copy the elements of list2 into the new list
    for (size_t i = 0; i < list2->length; i++)
    {
        new_list->elements[i + list1->length] = list2->elements[i];
    }

    return new_list;
}

// filter list returning only values that satisfy the filter function
list_t *filter_list(list_t *list, bool (*filter)(list_element_t))
{
    // Calculate the length of the new list
    size_t new_length = 0;
    for (size_t i = 0; i < list->length; i++)
    {
        if (filter(list->elements[i]))
        {
            new_length++;
        }
    }

    // Allocate memory for the new list
    list_t *new_list = (list_t *)malloc(sizeof(list_t) + new_length * sizeof(list_element_t));

    if (new_list == NULL)
    {
        // handle error if malloc fails
        return NULL;
    }

    // Set the length of the new list
    new_list->length = new_length;

    // Copy the filtered elements into the new list
    size_t j = 0;
    for (size_t i = 0; i < list->length; i++)
    {
        if (filter(list->elements[i]))
        {
            new_list->elements[j] = list->elements[i];
            j++;
        }
    }

    return new_list;
}

// returns the length of the list
size_t length_list(list_t *list)
{
    return (list->length);
}

// return a list of elements whose values equal the list value transformed by
// the mapping function
list_t *map_list(list_t *list, list_element_t (*map)(list_element_t))
{
    // Allocate memory for the new list
    list_t *new_list = (list_t *)malloc(sizeof(list_t) + list->length * sizeof(list_element_t));

    if (new_list == NULL)
    {
        // handle error if malloc fails
        return NULL;
    }

    // Set the length of the new list
    new_list->length = list->length;

    // Apply the map function to each element of the list
    for (size_t i = 0; i < list->length; i++)
    {
        new_list->elements[i] = map(list->elements[i]);
    }

    return new_list;
}

// folds (reduces) the given list from the left with a function
list_element_t foldl_list(list_t *list, list_element_t initial,
                          list_element_t (*foldl)(list_element_t,
                                                  list_element_t))
{
    if (list)
    {
        for (size_t i = 0; i < list->length; i++)
            initial = foldl(initial, list->elements[i]);
    }
    return initial;
}

// folds (reduces) the given list from the right with a function
list_element_t foldr_list(list_t *list, list_element_t initial,
                          list_element_t (*foldr)(list_element_t,
                                                  list_element_t))
{
    if (list)
    {
        for (size_t i = 0; i < list->length; i++)
            initial = foldr(list->elements[list->length - i - 1], initial);
    }
    return initial;
}

// reverse the elements of the list
list_t *reverse_list(list_t *list)
{
    // Allocate memory for the new list
    list_t *new_list = (list_t *)malloc(sizeof(list_t) + list->length * sizeof(list_element_t));

    if (new_list == NULL)
    {
        // handle error if malloc fails
        return NULL;
    }

    // Set the length of the new list
    new_list->length = list->length;

    // Copy the elements from the original list in reverse order
    for (size_t i = 0; i < list->length; i++)
    {
        new_list->elements[i] = list->elements[list->length - i - 1];
    }

    return new_list;
}

// destroy the entire list
// list will be a dangling pointer after calling this method on it
void delete_list(list_t *list)
{
    free(list);
}