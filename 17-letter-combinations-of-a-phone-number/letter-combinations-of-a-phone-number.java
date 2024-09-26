class Solution {
    public void backtracking(int index, String curr, List<String> result, String digits, HashMap<Character, List<Character>> numberToLetter){
        if(curr.length() == digits.length()){
            result.add(curr);
            return;
        }
        for (Character i:  numberToLetter.get(digits.charAt(index)))
            backtracking(index + 1, curr + i, result, digits, numberToLetter);

    }

        
    public List<String> letterCombinations(String digits) {
        HashMap<Character, List<Character>> numberToLetter = new HashMap<Character, List<Character>>();
        numberToLetter.put('2', Arrays.asList('a','b','c'));
        numberToLetter.put('3', Arrays.asList('d','e','f'));
        numberToLetter.put('4', Arrays.asList('g','h','i'));
        numberToLetter.put('5', Arrays.asList('j','k','l'));
        numberToLetter.put('6', Arrays.asList('m','n','o'));
        numberToLetter.put('7', Arrays.asList('p','q','r','s'));
        numberToLetter.put('8', Arrays.asList('t','u','v'));
        numberToLetter.put('9', Arrays.asList('w','x','y','z'));
        
        List<String> result = new ArrayList<String>();
        if (digits.length() > 0)
            backtracking(0,"", result, digits, numberToLetter);
        return result;
    }
}