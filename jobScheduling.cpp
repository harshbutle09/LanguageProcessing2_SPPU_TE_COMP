// Time complexity O(N^2)
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

    vector<bool> timeline(maxi + 1 , 0); // for 1 Based indexing
    for(int i = 0 ; i < n ; i ++){
        int currentDeadline = schedule[i].second;
        for(int j = currentDeadline ; j > 0 ; j --){
            if(timeline[j] == 0){
                timeline[j] = 1;
                totalProfit += schedule[i].first;
                totalJobs += 1;
                break;
            }
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