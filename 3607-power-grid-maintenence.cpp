class PowerGrid {
public:
    int id;
    priority_queue<int, vector<int>, greater<int>> powerGridEnabledStationsPq;
    PowerGrid(int id) {
        this->id = id;
    }
};

class Solution {
private:
    void initializeStationInformationlMap(unordered_map<int, pair<bool, int>>& stationInformationMap, int c) {
        for (int i = 1; i < c + 1; ++i) {
            stationInformationMap.insert({i, {true, 0}});
        } 
    }
    unordered_map<int, vector<int>> initializeAdjacencyList(vector<vector<int>>& connections) {
        unordered_map<int, vector<int>> result;
        for (const auto& connection : connections) {
            result[connection[0]].push_back(connection[1]);
            result[connection[1]].push_back(connection[0]);
        }
        return result;
    }
    void discoverConnectedPowerGrids(unordered_map<int, pair<bool,int>>& stationInformationMap,
                                    unordered_map<int, vector<int>>& adjMap,
                                    vector<PowerGrid>& powerGrids, int c) 
    {
        unordered_set<int> discoveredPowerGrids;
        int powergridCounter = 0;

        for (int i = 1; i < c + 1; ++i) {
            if (discoveredPowerGrids.find(i) != discoveredPowerGrids.end()) {
                continue;
            }

            PowerGrid powerGrid(powergridCounter);
            queue<int> bfs;
            bfs.push(i);

            while (!bfs.empty()) {
                int currStation = bfs.front();
                bfs.pop();

                if (discoveredPowerGrids.find(currStation) != discoveredPowerGrids.end()) {
                    continue;
                }
                
                stationInformationMap[currStation].second = powergridCounter;
                powerGrid.powerGridEnabledStationsPq.push(currStation);
                discoveredPowerGrids.insert(currStation);

                for (int i = 0; i < adjMap[currStation].size(); ++i) {
                    if (discoveredPowerGrids.find(adjMap[currStation][i]) != discoveredPowerGrids.end()) {
                        continue;
                    }

                    bfs.push(adjMap[currStation][i]);
                }
            }

            powerGrids.push_back(powerGrid);
            powergridCounter++;
        }
    }
    void handleMaintenenceCheck(int station, unordered_map<int, pair<bool,int>>& stationInformationMap, 
                            vector<PowerGrid>& powerGrids, vector<int>& queryResults) 
    {
        // get station information
        bool stationIsOperational = stationInformationMap[station].first;
        int powerGridIndex = stationInformationMap[station].second;

        if (stationIsOperational) {
            queryResults.push_back(station);
            return;
        }

        PowerGrid& powerGrid = powerGrids[powerGridIndex];
        bool foundStationToResolve = false;

        while (!powerGrid.powerGridEnabledStationsPq.empty()) {
            int nextStation = powerGrid.powerGridEnabledStationsPq.top();
            if (stationInformationMap[nextStation].first) {
                queryResults.push_back(nextStation);
                foundStationToResolve = true;
                break;
            }

            powerGrid.powerGridEnabledStationsPq.pop();
        }

        if (!foundStationToResolve) {
            queryResults.push_back(-1);
        }
    }
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        unordered_map<int, pair<bool,int>> stationInformationMap;
        initializeStationInformationlMap(stationInformationMap, c);
        unordered_map<int, vector<int>> adjMap = initializeAdjacencyList(connections);
        vector<PowerGrid> powerGrids;
        discoverConnectedPowerGrids(stationInformationMap, adjMap, powerGrids, c);
        
        vector<int> queryResults;
        // finally, after everything is initialized, we can process the queries

        for (const auto& query : queries) {
            if (query[0] == 1) {
                handleMaintenenceCheck(query[1], stationInformationMap, powerGrids, queryResults);
            }
            else {
                // we dont need to remove from the PQ as we do it in the maintenence check
                stationInformationMap[query[1]].first = false;
            }
        }

        return queryResults;
    }
};
