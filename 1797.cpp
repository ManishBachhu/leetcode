class AuthenticationManager {
unordered_map<string, int> tokenTtlMap;
priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> tokensPq;
int ttl;

void cleanUp(int currentTime) {
    while(!tokensPq.empty()) {
        auto token = tokensPq.top();
        if(token.first > currentTime)
            break;

        tokensPq.pop();
        if(token.first == tokenTtlMap[token.second])
            tokenTtlMap.erase(token.second);
    }
}

public:
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        tokenTtlMap[tokenId] = currentTime + ttl;
        tokensPq.push(pair<int, string>{currentTime + ttl, tokenId});
    }
    
    void renew(string tokenId, int currentTime) {
        cleanUp(currentTime);

        // If token is not expired, update ttl of token and
        // add a new token to queue. (old token will get popped eventually)
        if(tokenTtlMap.find(tokenId) != tokenTtlMap.end()) {
            tokenTtlMap[tokenId] = currentTime + ttl;
            tokensPq.push(pair<int, string>{currentTime + ttl, tokenId});
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        cleanUp(currentTime);
        return tokenTtlMap.size();
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
