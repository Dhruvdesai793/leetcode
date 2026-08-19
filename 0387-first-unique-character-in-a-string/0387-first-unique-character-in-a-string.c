int firstUniqChar(char* s) {
    int store[26] = {0};
    int len = strlen(s);

    for(int i =0; i<len; i++){
        store[s[i] - 'a']++;
    }

    for(int i = 0; i < len; i++){
        if(store[s[i] - 'a'] == 1){
            return i;
        }
    }
    return -1;
}