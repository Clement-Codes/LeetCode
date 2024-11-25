
class Solution {
    class values{
        int location;
        int lenght;
        String bb;
        values(int location, int lenght, String bb){
            this.location = location;
            this.lenght = lenght;
            this.bb = bb;
        }
    };
    public int slidingPuzzle(int[][] board) {
        HashMap<Integer, int[]> moves = new HashMap(){{ put(0, new int[]{1, 3});
            put(1, new int[]{0, 2, 4});
            put(2, new int[]{1, 5});
            put(3, new int[]{0, 4});
            put(4, new int[]{1, 3, 5});
            put(5, new int[]{2, 4});
        }};
        StringBuilder ss = new StringBuilder();
        for (int r[]: board)
            for (int c: r)
                ss.append(String.valueOf(c));
        String b;
        b = ss.toString();
        Queue<values> q = new LinkedList<values>();
        int t = b.indexOf('0');
        q.add(new values(t, 0, b));
        String f = "123450";
        Set<String> visited = new HashSet<>();
        visited.add(b);
        while(q.size() > 0){
            values temp = q.poll();
            if (temp.bb.equals(f))
                return temp.lenght;
            for (int i: moves.get(temp.location)){
                StringBuilder temp2 = new StringBuilder(temp.bb);
                char tt = temp.bb.charAt(i);
                temp2.setCharAt(i, temp2.charAt(temp.location));
                temp2.setCharAt(temp.location, tt);
                if (!visited.contains(temp2.toString())){
                    visited.add(temp2.toString());
                    q.add(new values(i, temp.lenght + 1, temp2.toString()));
                }
            }
        }
        return -1;    
    }
}