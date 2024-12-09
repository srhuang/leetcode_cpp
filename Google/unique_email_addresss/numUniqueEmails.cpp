    
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        for(string &email:emails)
        {
            string cleanEmail;
            for(char c:email)
            {
                if(c=='+'||c=='@') break;
                if(c=='.') continue;
                cleanEmail += c;
            }

            //add the domain name
            cleanEmail += email.substr(email.find('@'));

            //add into set
            st.insert(cleanEmail);
        }
        return st.size();        
    }
};

int main(int argc, char const *argv[]){


    //solution
    Solution s;

    //answer
    int answer;

    //test data
    vector<string> emails={
        "test.email+alex@leetcode.com",
        "test.e.mail+bob.cathy@leetcode.com",
        "testemail+david@lee.tcode.com"};

    //execute
    answer = s.numUniqueEmails(emails);

    cout << "Anser is :" << answer << endl;
    return 0;
}
