
/*
There are n different online courses numbered from 1 to n. Each course has some duration(course length) t and closed on dth day. A course should be taken continuously for t days and must be finished before or on the dth day. You will start at the 1st day.

Given n online courses represented by pairs (t,d), your task is to find the maximal number of courses that can be taken.

Example:

Input: [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]
Output: 3
Explanation: 
There're totally 4 courses, but you can take 3 courses at most:
First, take the 1st course, it costs 100 days so you will finish it on the 100th day, and ready to take the next course on the 101st day.
Second, take the 3rd course, it costs 1000 days so you will finish it on the 1100th day, and ready to take the next course on the 1101st day. 
Third, take the 2nd course, it costs 200 days so you will finish it on the 1300th day. 
The 4th course cannot be taken now, since you will finish it on the 3300th day, which exceeds the closed date.
*/

bool com(const vector<int>& v1, const vector<int>& v2) 
{ 
        return v1[1] < v2[1]; 
} 

class Solution {
public:

    int scheduleCourse(vector<vector<int>>& c) {
        int n = c.size();
        sort(c.begin(), c.end(), com);// sort according to end time 
        priority_queue<int> pq;// larget always comes to front 
        int time = 0;// mark start time
        for(int i=0; i<n; i++) {
            time += c[i][0];
            pq.push(c[i][0]);// push the len of the course to priority que
            
            if(time>c[i][1]){// if start time exceeds ith course end time
                time  -= pq.top();// pop out the course that last longest 
                pq.pop();
            }
        }
        return pq.size();
    }
    
// my understanding version: 
    bool com(const vector<int>& v1, const vector<int>& v2) 
{ 
        return v1[1] < v2[1]; 
} 
// MEMORY EXCEED
//Dfs recursive with cache O(n*M) where M is max course ending time, n is # of courses
//Space  o(n)(M) -> can be optimized to O(M) if using bottom-up DP
class Solution {  
    public static int scheduleCourse(int[][] courses){
        if(courses == null || courses.length ==0) return 0;
        int m = courses.length; 
        Arrays.sort(courses, (i, j) -> i[1] - j[1]);
        int[][] cache = new int[m][courses[m-1][1]+1];//courses[m-1][1]+1] =3200+1， total 3201*4 elements, initialize to 0 
        return schedule(courses, 0, 0,cache);
    }
    public static int schedule(int[][] courses, int day, int index, int[][] cache){
        //base
        if(index == courses.length){
            return 0;
        }
        if(cache[index][day]!=0) return cache[index][day];
        int taken = 0;
        int[] cur = courses[index];
        if(day + cur[0] <= cur[1]){
            taken = 1 + schedule(courses, day + cur[0], index+1, cache); 
        }
        int not_taken = schedule(courses, day, index+1, cache);
        cache[index][day] = Math.max(taken, not_taken);// if index =1, mean take course 1, max amount of couses can be take
        return cache[index][day];
    }
    
}

// my own thought version :Recursion with Memoization

public class Solution {
    public int scheduleCourse(int[][] courses) {
        Arrays.sort(courses, (a, b) -> a[1] - b[1]);
        Integer[][] memo = new Integer[courses.length][courses[courses.length - 1][1] + 1];
        return schedule(courses, 0, 0, memo);
    }
    public int schedule(int[][] courses, int i, int time, Integer[][] memo) {
        if (i == courses.length)
            return 0;
        if (memo[i][time] != null)
            return memo[i][time];
        int taken = 0;
        if (time + courses[i][0] <= courses[i][1])
            taken = 1 + schedule(courses, i + 1, time + courses[i][0], memo);
        int not_taken = schedule(courses, i + 1, time, memo);
        memo[i][time] = Math.max(taken, not_taken);
        return memo[i][time];
    }
}


// method1: DFS no cache O(2^n) recursion, TIME EXCEED
class Solution {        
       
    public static int scheduleCourse (int[][] courses) {
        Arrays.sort(courses, (i,j)->i[1]-j[1]);
        return helper(courses, 0, 0);
    }
    private static int helper(int[][] course, int day, int index){
        //base
        if(index == course.length){
            return 0;
        }
        int[] cur = course[index];
        int taken = 0;
        if(day+cur[0] <= cur[1]){
            taken = 1+helper(course, day+cur[0], index+1);
        }
        int not_taken = helper(course, day, index+1);
        return Math.max(taken, not_taken);
    }
}

// Approach 2: Recursion with Memoization method2: MEMORY EXCEED
//Dfs recursive with cache O(n*M) where M is max course ending time, n is # of courses
//Space  o(n)(M) -> can be optimized to O(M) if using bottom-up DP
class Solution {  
    public static int scheduleCourse(int[][] courses){
        if(courses == null || courses.length ==0) return 0;
        int m = courses.length; 
        Arrays.sort(courses, (i, j) -> i[1] - j[1]);
        int[][] cache = new int[m][courses[m-1][1]+1];
        return schedule(courses, 0, 0,cache);
    }
    public static int schedule(int[][] courses, int day, int index, int[][] cache){
        //base
        if(index == courses.length){
            return 0;
        }
        if(cache[index][day]!=0) return cache[index][day];
        int taken = 0;
        int[] cur = courses[index];
        if(day + cur[0] <= cur[1]){
            taken = 1 + schedule(courses, day + cur[0], index+1, cache); 
        }
        int not_taken = schedule(courses, day, index+1, cache);
        cache[index][day] = Math.max(taken, not_taken);
        return cache[index][day];
    }
    
}
	//TLE of memory, which is expected. Think about the Salesman problem. 

 //method 3   
//greedy O(nlogn) + o(nlogn) space:O( n) PASS,faster and Smaller than c++ version
    /*
    Take the ealiest course that can be finished, otherwise, remove the longest course, and replaced it with multiple shorter courses. since the max course number is the goal.*/
    

class Solution {        

    public static int scheduleCourse(int[][] courses){
            Arrays.sort(courses, (i,j)->i[1]-j[1]);
            PriorityQueue<Integer> q = new PriorityQueue<>((i,j)->j-i); //max heap
            int time =0;
            for(int i =0;i<courses.length;i++){
                int[] cur = courses[i];
                time+=cur[0];
                q.add(cur[0]);
                if(time>cur[1]) time-=q.poll();
            }
            return q.size();

        }      
}

/// FROM LEETCODE PROBLEMS


/*Approach 1: Brute Force
Algorithm

The most naive solution will be to consider every possible permutation of the given courses and to try to take as much courses as possible by taking the courses in a serial order in every permutation. We can find out the maximum number of courses that can be taken from out of values obtained from these permutations.

Complexity Analysis

Time complexity : O\big((n+1)!\big)O((n+1)!). A total of n!n! permutations are possible for the coursescourses array of length nn. For every permutation, we scan over the nn elements of the permutation to find the number of courses that can be taken in each case.

Space complexity : O(n)O(n). Each permutation needs nn space.*/

//Approach 2: Recursion with Memoization
/*In order to remove this redundancy, we make use of a memoization array memomemo, such that memo[i][j]memo[i][j] is used to store the result of the function call schedule(courses, i, time). Thus, whenever the same function call is made again, we can return the result directly from the memomemo array. This helps to prune the search space to a great extent.*/
public class Solution {
    public int scheduleCourse(int[][] courses) {
        Arrays.sort(courses, (a, b) -> a[1] - b[1]);
        Integer[][] memo = new Integer[courses.length][courses[courses.length - 1][1] + 1];
        return schedule(courses, 0, 0, memo);
    }
    public int schedule(int[][] courses, int i, int time, Integer[][] memo) {
        if (i == courses.length)
            return 0;
        if (memo[i][time] != null)
            return memo[i][time];
        int taken = 0;
        if (time + courses[i][0] <= courses[i][1])
            taken = 1 + schedule(courses, i + 1, time + courses[i][0], memo);
        int not_taken = schedule(courses, i + 1, time, memo);
        memo[i][time] = Math.max(taken, not_taken);
        return memo[i][time];
    }
}


/*Approach 3: Iterative Solution

We are sure of the fact that by removing the j^{th}j 
th
  course, we can fit in the current course, because, course_jcourse 
j
​	
  was already fitting in the duration available till now. Since, duration_i < duration_jduration 
i
​	
 <duration 
j
​	
 , the current course can surely take its place. Thus, we look for a course from amongst the taken courses having a duration larger than the current course.

But why are we doing this replacement? The answer to this question is as follows. By replacing the j^{th}j 
th
  course, with the i^{th}i 
th
  course of a relatively smaller duration, we can increase the time available for upcoming courses to be taken. An extra duration_j - duration_iduration 
j
​	
 −duration 
i
​	
  time can be made available by doing so. */
public class Solution {
    public int scheduleCourse(int[][] courses) {
        System.out.println(courses.length);
        Arrays.sort(courses, (a, b) -> a[1] - b[1]);
        int time = 0, count = 0;
        for (int i = 0; i < courses.length; i++) {
            if (time + courses[i][0] <= courses[i][1]) {
                time += courses[i][0];
                count++;
            } else {
                int max_i = i;
                for (int j = 0; j < i; j++) {// optimize sol change i to count to reduce iteration from O(n) to O(1)
                    if (courses[j][0] > courses[max_i][0])
                        max_i = j;
                }
                if (courses[max_i][0] > courses[i][0]) {
                    time += courses[i][0] - courses[max_i][0];
                }
                courses[max_i][0] = -1;// change to courses[max_i] = courses[i] after change from j to count
            }
        }
        return count;
    }
}

Time complexity : O(n^2)O(n 
2
 ). We iterate over the countcount array of size nn once. For every element currently considered, we could scan backwards till the first element, giving O(n^2)O(n 
2
 ) complexity. Sorting the countcount array takes O\big(n \log n\big)O(nlogn) time for countcount array.

Space complexity : O(1)O(1). Constant extra space is used.

*/

/* BEST APPROACH!
Approach 4: Optimized Iterative
GREAT test case for below code 
[[700,2000],[1100,1300],[1200,1250],[800,3000]]
We can bring in some optimization here. For this, we should search among only those courses which have been taken(and not the ones which haven't been taken).

To do so, as we iterate over the coursescourses array, we also keep on updating it, such that the first countcount number of elements in this array now correspond to only those countcount number of courses which have been taken till now.

Thus, whenever we update the countcount to indicate that one more course has been taken, we also update the courses[count]courses[count] entry to reflect the current course that has just been taken.

Whenever, we find a course for which time + duration_i > end\_day_itime+duration 
i
​	
 >end_day 
i
​	
 , we find a max_imax 
i
​	
  course from only amongst these first countcount number of courses in the coursescourses array, which indicate the courses that have been taken till now.

Also, instead of marking this max_i^{th}max 
i
th
​	
  course with a \text{-1}-1, we can simply replace this course with the current course. Thus, the first countcount courses still reflect the courses that have been taken till now.

Time complexity : O(n*count) We iterate over a total of nn elements of the coursescourses array. For every element, we can traverse backwards upto atmost countcount(final value) number of elements.

Space complexity : O(1). Constant extra space is used.

*/
public class Solution {
    public int scheduleCourse(int[][] courses) {
        System.out.println(courses.length);
        Arrays.sort(courses, (a, b) -> a[1] - b[1]);
        int time = 0, count = 0;
        for (int i = 0; i < courses.length; i++) {
            if (time + courses[i][0] <= courses[i][1]) {
                time += courses[i][0];
                courses[count++] = courses[i];
            } else {
                int max_i = i;
                for (int j = 0; j < count; j++) {
                    if (courses[j][0] > courses[max_i][0])
                        max_i = j;
                }
                if (courses[max_i][0] > courses[i][0]) {
                    time += courses[i][0] 
                    time -= courses[max_i][0];
                    courses[max_i] = courses[i];
                }
            }
        }
        return count;
    }
}
/*Approach 5: Extra List
In the last approach, we updated the coursecourse array itself so that the first countcount elements indicate the countcount number of courses that have been taken till now. If it is required to retain the coursescourses array as such, we can do the same job by maintaining a separate list valid\_listvalid_list which is the list of those courses that have been taken till now.

Thus, to find the max_imax 
i
​	
  course, we need to search in this list only. Further, when replacing this max_i^{th}max 
i
th
​	
  course with the current course, we can replace this max_imax 
i
​	
  course in the list with current course directly. The rest of the method remains the same as the last approach.*/
public class Solution {
    public int scheduleCourse(int[][] courses) {
        Arrays.sort(courses, (a, b) -> a[1] - b[1]);
        List< Integer > valid_list = new ArrayList < > ();
        int time = 0;
        for (int[] c: courses) {
            if (time + c[0] <= c[1]) {
                valid_list.add(c[0]);
                time += c[0];
            } else {
                int max_i=0;
                for(int i=1; i < valid_list.size(); i++) { // for (int j = 0; j < count; j++)
                    if(valid_list.get(i) > valid_list.get(max_i))// if (courses[j][0] > courses[max_i][0])
                        max_i = i;
                }
                if (valid_list.get(max_i) > c[0]) {
                    time += c[0] - valid_list.get(max_i);
                    valid_list.set(max_i, c[0]);//The method set(int index, Element E) updates the element of specified index with the given element E.
                }
            }
        }
        return valid_list.size();
    }
}
/*
Time complexity : O(n*m) We iterate over a total of nn elements of the coursescourses array. For every element, we can traverse over atmost mm number of elements. Here, mm refers to the final length of the valid\_listvalid_list.

Space complexity : O(n) The valid\_listvalid_list can contain atmost nn courses.

*/
/*Approach 6: Priority Queue
The iteration over the sorted coursescourses remains the same as in the last approaches. Whenver the current course(i^{th}i 
th
  course) can be taken(time + duration_i ≤ end\_day_i), it is added to the queuequeue and the value of the current time is updated to time + duration_itime+duration 
i
​	
 .

If the current course can't be taken directly, as in the previous appraoches, we need to find a course whose duration duration_jduration 
j
​	
  is maximum from amongst the courses taken till now. Now, since we are maintaing a Max-Heap, queuequeue, we can obtain this duration directly from this queuequeue. If the duration duration_j > duration_iduration 
j
​	
 >duration 
i
​	
 , we can replace the j^{th}j 
th
  course, with the current one.

Thus, we remove the duration_jduration 
j
​	
  from the queuequeue and add the current course's duration duration_iduration 
i
​	
  to the queuequeue. We also need to make proper adjustments to the timetime to account for this replacement done.
*/
public class Solution {
    public int scheduleCourse(int[][] courses) {
        Arrays.sort(courses, (a, b) -> a[1] - b[1]);
        PriorityQueue < Integer > queue = new PriorityQueue < > ((a, b) -> b - a);
        int time = 0;
        for (int[] c: courses) {
            if (time + c[0] <= c[1]) {
                queue.offer(c[0]);
                time += c[0];
            } else if (!queue.isEmpty() && queue.peek() > c[0]) {
                time += c[0] - queue.poll();
                queue.offer(c[0]);
            }
        }
        return queue.size();
    }
}
/*
Time complexity : O(nlogn). At most nn elements are added to the queuequeue. Adding each element is followed by heapification, which takes O\big(\log n\big)O(logn) time.

Space complexity : O(n). The queuequeue containing the durations of the courses taken can have atmost nn elements
*/


