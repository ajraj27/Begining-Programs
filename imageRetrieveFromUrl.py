import random
import urllib.request

def downloadImage(url):
    num=random.randrange(1,1000)
    name=str(num)+".jpeg"
    urllib.request.urlretrieve(url,name)

downloadImage("http://www.trbimg.com/img-594418cb/turbine/la-et-mg-leonardo-dicaprio-in-scotland-20170616")    
