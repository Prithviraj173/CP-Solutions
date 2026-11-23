class ProductOfNumbers {
private:
    vector<int> pref;
    int i = 0;
public:
    ProductOfNumbers() {
        pref.push_back(1);
        i = 0;
    }
    
    void add(int num) {
        if(num == 0) {
            pref = {1};
            i = 0;
        } else {
            pref.push_back(pref[i] * num);
            i++;
        }
    }
    
    int getProduct(int k) {
        if(k > i) return 0;
        return pref[i] / pref[i - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */