def activity_selection(activities):
    # activities is a list of tuples: (start_time, finish_time)
    # Sort activities by their finish times
    activities.sort(key=lambda x: x[1])

    print("Selected Activities:")

    # The first activity always gets selected
    i = 0
    print(activities[i])

    # Consider rest of the activities
    for j in range(1, len(activities)):
        # If this activity has start time greater than or equal to the finish time of previously selected activity, then select it
        if activities[j][0] >= activities[i][1]:
            print(activities[j])
            i = j
