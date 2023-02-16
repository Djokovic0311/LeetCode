# """
# This is HtmlParser's API interface.
# You should not implement it, or speculate about its implementation
# """
#class HtmlParser(object):
#    def getUrls(self, url):
#        """
#        :type url: str
#        :rtype List[str]
#        """

class Solution:
    def crawl(self, startUrl: str, htmlParser: 'HtmlParser') -> List[str]:
        start_hostname = "http://" + startUrl.split('//')[1].split('/')[0]

        output = set()
        to_explore = set()
        to_explore.add(startUrl)

        while to_explore:
            url = to_explore.pop()
            output.add(url)

            next_urls = htmlParser.getUrls(url)
            
            for next_url in next_urls:
                if next_url not in to_explore and next_url not in output:
                    if next_url.startswith(start_hostname):
                        to_explore.add(next_url)

        return list(output)
        
