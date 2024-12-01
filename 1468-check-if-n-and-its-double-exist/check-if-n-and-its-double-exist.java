class Solution {
    public boolean checkIfExist(int[] arr) {
        HashSet<Integer> visited = new HashSet<Integer>();

        for (int i: arr){
            if (visited.contains(i * 2) || (i  % 2 == 0 && visited.contains(i / 2)))
                return true;
            visited.add(i);
        }
        return false; 
    }
}