#ifndef ACTIVITYSELECTION_H
#define ACTIVITYSELECTION_H

#include <vector>
#include <algorithm>

struct Activity {
    int start;
    int finish;
};

void activitySelection(std::vector<Activity>& activities);

#endif // ACTIVITYSELECTION_H
