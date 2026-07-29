class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>stud ;
        stack<int>sand; 
        int m = students.size();
        int n =  sandwiches.size();
        for(int i = 0 ; i < m ; i++)
        {
            stud.push(students[i]);
        }
        for(int i = n - 1 ; i >= 0 ; i--)
        {
            sand.push(sandwiches[i]);
        }

        int count = 0 ;
        while(!stud.empty())
        {
            if(stud.front() == sand.top())
            {
                count = 0 ;
                stud.pop();
                sand.pop();
            }
            else
            {
                int not_match = stud.front() ;
                stud.pop();
                count++;
                stud.push(not_match);
            }
            if( stud.size() == count)
            {
                break;
            }
        }
        return stud.size() ;

    }
};