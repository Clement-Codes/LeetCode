class Solution {
    int i = 0;
    String str;

    boolean helper(){
        char c= str.charAt(i);
        i += 1;
        if (c == 't') return true;
        if (c == 'f') return false;
        i += 1;
        if (c == '!'){
            boolean res = ! helper();
            i += 1;
            return res;
        }
        List<Boolean> container = new ArrayList<Boolean>();
        while (str.charAt(i) != ')'){
            if (str.charAt(i) != ',') container.add(helper());
            else i += 1;
        }
        i += 1;
        boolean result = container.get(0);
        if (c == '&'){
            for (int ii = 1; ii < container.size(); ii++) result &= container.get(ii);
        }
        if (c == '|'){
            for (int ii = 1; ii < container.size(); ii++) result |= container.get(ii);
        }

        return result;
    }

    public boolean parseBoolExpr(String expression) {
        str = expression;
        return helper();
    }
}