#include "ActivitySelection.h"
#include <iostream>

// Custom comparator for sorting activities by finish time
bool compareActivities(const Activity& a, const Activity& b) {
    return a.finish < b.finish;
}

void activitySelection(std::vector<Activity>& activities) {
    // Sort activities by their finish times
    std::sort(activities.begin(), activities.end(), compareActivities);

    std::cout << "Selected Activities:" << std::endl;

    // The first activity always gets selected
    int i = 0;
    std::cout << "(" << activities[i].start << ", " << activities[i].finish << ")" << std::endl;

    // Consider rest of the activities
    for (int j = 1; j < activities.size(); ++j) {
        // If this activity has start time greater than or equal to the finish time of previously selected activity, then select it
        if (activities[j].start >= activities[i].finish) {
            std::cout << "(" << activities[j].start << ", " << activities[j].finish << ")" << std::endl;
            i = j;
        }
    }
}
