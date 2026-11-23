class ProductOfNumbers {
public:
vector<int> arr;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(arr.empty()){
            arr.push_back(num);
        } else {
         arr.push_back(num*arr.back());
        }
        if(num == 0){
            arr.clear();
        }
    }
    
    int getProduct(int k) {
        int n = arr.size();
        if(k>n) return 0;
        if(k == n) return arr[n-1];
        int ans = arr[n-1]/arr[n-k-1];
        return ans; 
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */