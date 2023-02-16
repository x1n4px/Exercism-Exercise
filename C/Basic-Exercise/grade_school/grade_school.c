#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include "grade_school.h"
/** Students are stored in an array, in sorted order.
 */
void init_roster(roster_t *roster) {
    roster->count = 0;
    // Leave roster->students alone uncleared, since we expect
    // not to access them given the count of 0.
}
/** Sort by grade, then name. */
static int compare_student(const void *p1, const void *p2) {
    const student_t *s1 = (student_t *) p1;
    const student_t *s2 = (student_t *) p2;
    if (s1->grade < s2->grade) {
        return -1;
    } else if (s1-> grade > s2->grade) {
        return 1;
    } else {
        return strcmp(s1->name, s2->name);
    }
}
/** Attempt to find the student anywhere.
    If found, do nothing, else try to append to the end, then resort.
 
    Fail if the roster is already full! */
bool add_student(roster_t *roster, const char *name, uint8_t grade) {
    const int all_count = roster->count;
    for (int j = 0; j < all_count; j++) {
        // Assume all lengths and bounds are correct.
        if (strcmp(roster->students[j].name, name) == 0) {
            return false;
        }
    }
    assert(roster->count < MAX_STUDENTS);
    roster->students[roster->count].grade = grade;
    // Assume all lengths and bounds are correct.
    strcpy(roster->students[roster->count].name, name);
    roster->count++;
    qsort(roster->students, roster->count, sizeof(student_t), compare_student);
    return true;
}
/** Return a new roster, sorted by name. */
roster_t get_grade(const roster_t *roster, uint8_t grade) {
    roster_t result = { 0 };
    // Filter roster.
    const int all_count = roster->count;
    for (int j = 0; j < all_count; j++) {
        if (roster->students[j].grade == grade) {
            result.students[result.count] = roster->students[j];
            result.count++;
        }
    }
    return result;
}
