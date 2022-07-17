#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	map<string, string> mp; //store the mapping from string to string.

	// Encodes a URL to a shortened URL.
	string encode(string longUrl) {
		string str = "";
		while (mp.find(str) != mp.end()) { //jb tk "str" milti rhegi map me
			//LOGIC: 0 to 100 int ko char me convert kr rhe(ASCII value of char in range 0 to 100 are being converted from int to char)
			str += (char)floor(rand() % 100); //rand() %100--> range from 0 to 100;
		}


		//ab jo str h vo unique h(map me nhi h)
		//toh map me iss str ke corresponding longUrl daal do
		cout << "str " << str << endl;
		mp[str] = longUrl;
		return str;
	}

	// Decodes a shortened URL to its original URL.
	string decode(string shortUrl) {
		return mp[shortUrl];
	}
};

int main() {
	/*
	PREREQUISITE:
	VIDEO LINK: https://www.youtube.com/watch?v=EPD3Or5xtNg&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=54
	QUESTION LINK: https://leetcode.com/problems/encode-and-decode-tinyurl/
	*/
	Solution obj;
	string encode = obj.encode("vaibhav");
	cout << obj.decode(encode) << endl;

	string encode2 = obj.encode("yooo");
	cout << obj.decode(encode2) << endl;

	string encode3 = obj.encode("hello");
	cout << obj.decode(encode3);
}