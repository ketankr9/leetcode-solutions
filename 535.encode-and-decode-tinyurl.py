#
# @lc app=leetcode id=535 lang=python
#
# [535] Encode and Decode TinyURL
#
# https://leetcode.com/problems/encode-and-decode-tinyurl/description/
#
# algorithms
# Medium (77.11%)
# Total Accepted:    78.3K
# Total Submissions: 101.5K
# Testcase Example:  '"https://leetcode.com/problems/design-tinyurl"'
#
# Note: This is a companion problem to the System Design problem: Design
# TinyURL.
# 
# TinyURL is a URL shortening service where you enter a URL such as
# https://leetcode.com/problems/design-tinyurl and it returns a short URL such
# as http://tinyurl.com/4e9iAk.
# 
# Design the encode and decode methods for the TinyURL service. There is no
# restriction on how your encode/decode algorithm should work. You just need to
# ensure that a URL can be encoded to a tiny URL and the tiny URL can be
# decoded to the original URL.
# 
#
class Codec:
    dic = dict()
    def calc(self, s):
        e = 3
        val = 0
        for i,c in enumerate(s):
            val += e**i*ord(c)
        val = val%62
        if val>52:
            return chr(ord('0')+val-52)
        elif val >= 26:
            return chr(ord('A') + (val-26))
        else:
            return chr(ord('a') + val)
    def encc(self, s):
        ret = ""
        for x in s.split('/'):
            if len(x)==0:
                continue
            ret += self.calc(x)
        return ret
    def encode(self, longUrl):
        """Encodes a URL to a shortened URL.
        
        :type longUrl: str
        :rtype: str
        """
        en = self.encc(longUrl)
        # print(en)
        self.dic[en] = longUrl
        return "http://tinyurl.com/" + en

    def decode(self, shortUrl):
        """Decodes a shortened URL to its original URL.
        
        :type shortUrl: str
        :rtype: str
        """
        return self.dic[shortUrl[19:]]

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))
