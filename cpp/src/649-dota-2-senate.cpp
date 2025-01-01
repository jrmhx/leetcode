/*
 * @lc app=leetcode id=649 lang=cpp
 *
 * [649] Dota2 Senate
 */

#include <string>
#include <deque>

using namespace std;


// @lc code=start
class Solution {
public:
    string predictPartyVictory(string senate) {
        deque<long long> dq, rq;
		int n = senate.length();
		for (int i = 0; i < n; i++){
			if(senate[i] == 'D'){
				dq.push_back(i);
			} else {
				rq.push_back(i);
			}
		}

		while (dq.size() != 0 && rq.size() !=0){
			long long d = dq.front();
			long long r = rq.front();
			if (d < r){
				rq.pop_front();
				dq.pop_front();
				dq.push_back(d+n);
			} else {
				dq.pop_front();
				rq.pop_front();
				rq.push_back(r+n);
			}
		}

		return dq.size() == 0 ? "Radiant" : "Dire";
    }
};
// @lc code=end

// RDDDDDDDDDDRD
// 

// string -> list 
// for each sentator S in list, 
// 
// 1. scanning for closest opp sentator at back
// 1.1 if found one kick them out 
//     else there's no opp -> vicory (return)
// 2. if not vic, pop_front S, push_back S

// senta = DRR ------> R

// dq: 0
// rq: 1 2