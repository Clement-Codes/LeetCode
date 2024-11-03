class Solution {
    public boolean rotateString(String s, String goal) {
        String t = s + s;
        return s.length() == goal.length() && t.contains(goal);
    }
}