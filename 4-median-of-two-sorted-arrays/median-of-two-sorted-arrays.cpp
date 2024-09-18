#include<cmath>
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& a = nums1;
        vector<int>& b = nums2;

        if (b.size() < a.size()) {
            swap(a, b);
        }


        int al = 0;
        int ar = a.size() - 1;

        while(true){
            
            int am = al + floor((ar - al)/2.0);
            int bm = floor((a.size() + b.size())/2.0) - am - 2;

            int AL = am >= 0 ? a[am] : INT_MIN;
            int AR = am + 1 < a.size() ? a[am + 1] : INT_MAX;

            int BL = bm >= 0 ? b[bm] : INT_MIN;
            int BR = bm + 1 < b.size() ? b[bm + 1] : INT_MAX;

            cout << al <<" "<< ar <<" "<< am <<" "<< bm <<" "<< AL <<" "<< AR <<" "<< BL <<" "<< BR <<" "<<"\n";
            if (AL <= BR && BL <= AR){
                if (floor((a.size() + b.size()) % 2) != 0){
                    return min(AR, BR);
                }
                else{
                    return (max(AL, BL) + min(AR, BR)) / 2.0;
                }
            }
            else if(AL < BR){
                al = am + 1;
            }
            else{
                ar = am - 1;
            }
        }
    }
};