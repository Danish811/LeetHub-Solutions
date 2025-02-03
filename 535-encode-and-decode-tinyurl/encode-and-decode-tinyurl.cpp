class Solution {
private:
   const string BASE_URL = "http://tinyurl.com/";
   map<string,string> M;
   int counter = 0;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
       counter++;
       string ShortUrl = BASE_URL + to_string(counter);
       M[ShortUrl] =  longUrl;
       return ShortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return M[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));