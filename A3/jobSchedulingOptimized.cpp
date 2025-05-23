// Time complexity O(NlogN)

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;
class Job{
    public:
    int id;
    int deadline;
    int profit;
    Job(int id , int deadline , int profit){
        this -> id = id;
        this -> deadline = deadline;
        this -> profit = profit;
    }
};
int find(int currentDeadline , vector<int>& parent){
    if(parent[currentDeadline] == currentDeadline){
        return currentDeadline;
    }
    return parent[currentDeadline] = find(parent[currentDeadline] , parent);
}
vector<int> jobSchedule(vector<Job*> allJobs){
    int totalProfit = 0;
    int totalJobs = 0;
    int n = allJobs.size();
    vector<int> ans;
    int maxi = INT_MIN;
    vector<pair<int , int>> schedule;
    for(int i = 0 ; i < n ; i ++){
        maxi = max(allJobs[i] -> deadline , maxi);
        pair<int , int> p = make_pair(allJobs[i] -> profit , allJobs[i] -> deadline);
        schedule.push_back(p);
    }
    sort(schedule.begin() , schedule.end() , greater<>());
    
    vector<int>parent(maxi + 1);
    for(int i = 0 ; i < parent.size() ; i ++){
        parent[i] = i;
    }
    for(int i = 0 ; i < n ; i ++){
        int currentDeadline = schedule[i].second;
        int slot = find(currentDeadline , parent);
        if(slot){
            totalJobs ++;
            totalProfit += schedule[i].first;
            parent[slot] = slot - 1;
        }
    }
    ans.push_back(totalJobs);
    ans.push_back(totalProfit);
return ans;
}
int main(){
    int n;
    cout << "Enter number of Jobs\n";
    cin >> n;
    vector<int> ans(2);
    int dead;
    int prof;
    vector<Job*> allJobs;
    for(int i = 1 ; i <= n ; i ++){
        cout << "Enter Profit for Job " << i << "\n";
        cin >> prof;
        cout << "Enter deadline for Job " << i << "\n";
        cin >> dead;
        Job *newJob = new Job(i , dead , prof );
        allJobs.push_back(newJob);
    }

    cout << "Following are the Jobs and their profits\n";
    cout <<"ID\tProfit\tDeadline\n";
    for(auto it : allJobs){
        cout << it -> id << "\t";
        cout << it -> profit << "\t";
        cout << it -> deadline << "\n";
    }
    ans = jobSchedule(allJobs);
    cout << "Maximum Profit generated: " << ans[1] << "\n";
    cout << "Total No. of jobs executed: "<< ans[0];

    return 0;
}