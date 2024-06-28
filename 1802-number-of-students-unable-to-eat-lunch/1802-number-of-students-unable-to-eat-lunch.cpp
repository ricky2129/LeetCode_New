class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> studentQueue, sandwichQueue;
        
        // Initialize the queues
        for (int student : students) {
            studentQueue.push(student);
        }
        for (int sandwich : sandwiches) {
            sandwichQueue.push(sandwich);
        }
        
        int count = 0; // This will count the consecutive moves where no student takes a sandwich
        
        while (!studentQueue.empty() && !sandwichQueue.empty()) {
            if (studentQueue.front() == sandwichQueue.front()) {
                // Student takes the sandwich
                studentQueue.pop();
                sandwichQueue.pop();
                count = 0; // Reset count since a sandwich was taken
            } else {
                // Student moves to the end of the line
                studentQueue.push(studentQueue.front());
                studentQueue.pop();
                count++;
                
                // If count equals the size of the student queue, it means no one in the queue wants the top sandwich
                if (count == studentQueue.size()) {
                    break;
                }
            }
        }
        
        return studentQueue.size();
    }
};
