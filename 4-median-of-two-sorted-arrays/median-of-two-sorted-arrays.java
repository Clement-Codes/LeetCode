class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] a = nums1, b = nums2;
        if(a.length > b.length){
            int temp[] = a;
            a = b;
            b = temp;
        }
        
        int al = 0;
        int ar = a.length - 1;

        while(true){
            int am = al + (int)Math.floor((ar - al) / 2.0);
            int bm = (int)Math.floor((a.length + b.length) / 2.0) - am - 2;

            int AL = am >= 0 ? a[am] : Integer.MIN_VALUE;
            int AR = am + 1 < a.length ? a[am + 1] : Integer.MAX_VALUE;

            int BL = bm >= 0 ? b[bm] : Integer.MIN_VALUE;
            int BR = bm + 1 < b.length ? b[bm + 1] : Integer.MAX_VALUE;
            
            System.out.printf("%d %d %d %d %d %d %d %d\n", al, ar, am, bm, AL, AR, BL, BR);
            
            if(AL <= BR  && BL <= AR){
                if((int)Math.floor((a.length + b.length) % 2.0) != 0) return Math.min(AR, BR);
                else return (Math.max(AL, BL) + Math.min(AR, BR)) / 2.0;
            }
            else if(AL < BR) al = am + 1;
            else ar = am - 1;
        }
    }
}