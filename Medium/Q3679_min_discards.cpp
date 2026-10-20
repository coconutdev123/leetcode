/*
You are given two integers w and m, and an integer array arrivals, where arrivals[i] is the type of item arriving on day i (days are 1-indexed).

Items are managed according to the following rules:

Each arrival may be kept or discarded; an item may only be discarded on its arrival day.
For each day i, consider the window of days [max(1, i - w + 1), i] (the w most recent days up to day i):
For any such window, each item type may appear at most m times among kept arrivals whose arrival day lies in that window.
If keeping the arrival on day i would cause its type to appear more than m times in the window, that arrival must be discarded.
Return the minimum number of arrivals to be discarded so that every w-day window contains at most m occurrences of each type.
*/

#include <vector>
#include <unordered_map>
#include <deque>


using namespace std;


    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {

        unordered_map<int, deque<int>> mp;

        int ans = 0;

        for(int i = 0; i < arrivals.size(); i++) {

            int x = arrivals[i];

            // Remove old occurrences of x
            while(!mp[x].empty() && mp[x].front() < i - w + 1) {
                mp[x].pop_front();
            }

            // Already m occurrences -> discard
            if(mp[x].size() >= m) {
                ans++;
            }
            else {
                // Keep this arrival
                mp[x].push_back(i);
            }
        }

        return ans;
    }


