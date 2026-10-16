class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        int n = asteroids.size();
        stack<int> st;
        for(int x: asteroids){
        bool alive = true;
            while(alive && st.size() > 0 && st.top() > 0 && x<0){
                if(abs(x) > st.top()){
                    st.pop();
                }else if (st.top() == -x) {
                    st.pop();
                    alive = false;
                }
                else {
                    alive = false;
                }
            }
            if(alive){
                st.push(x);
            }
        }
        stack<int> st1;
      while(st.size() > 0){
           st1.push(st.top());
            st.pop();
      }
      while(st1.size() > 0){
          ans.push_back(st1.top());
            st1.pop();
      }
        return ans;
    }
};