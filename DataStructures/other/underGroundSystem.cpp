/**
 * https://leetcode.com/problems/design-underground-system/
 */
#include<bits/stdc++.h>
using namespace std;

class UndergroundSystem {
public:
    map< pair<string,string>, pair<int,int> > stations;
    map< string , string > ps;
    map<string,int>pt;

    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        ps.emplace(make_pair(id,stationName));
        pt.emplace({id,t});

    }
    
    void checkOut(int id, string stationName, int t) {
        
    }
    
    double getAverageTime(string startStation, string endStation) {
        
    }
};