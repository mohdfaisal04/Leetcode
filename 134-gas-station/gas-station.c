int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int total_tank = 0;
    int current_tank = 0;
    int starting_station = 0;
    
    for (int i = 0; i < gasSize; ++i) {
        total_tank += gas[i] - cost[i];
        current_tank += gas[i] - cost[i];
        
        // If current tank is negative, reset starting station and tank
        if (current_tank < 0) {
            starting_station = i + 1;
            current_tank = 0;
        }
    }
    
    // If total_tank >= 0, it means a valid starting station exists
    return total_tank >= 0 ? starting_station : -1;
}
