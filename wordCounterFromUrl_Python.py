import requests
from bs4 import BeautifulSoup
import operator

def start(url):

    word_list=[]
    source_code=requests.get(url).text
    soup=BeautifulSoup(source_code,"lxml")

    for post_text in soup.findAll('a',{'class':"result-title hdrlnk"}):
        content=post_text.string
        words=content.lower().split()
        for each_word in words:
            word_list.append(each_word)
            
    clean_up_list(word_list)

def clean_up_list(word_list):
    clean_words_list=[]

    for word in word_list:
        symbol="!@#$%^&*()_+=-[]{}:\"<>?;',./"
        for i in range(len(symbol)):
            word=word.replace(symbol[i],"")

        if(len(word)>0):
             clean_words_list.append(word)

    create_dict(clean_words_list)             

def create_dict(clean_words_list):
    word_count={}

    for word in clean_words_list:
        word_count.setdefault(word,0)
        word_count[word]=word_count[word]+1

    for key,value in sorted(word_count.items(),key=operator.itemgetter(1)):
        print(key,value)                                    

start("https://cnj.craigslist.org/search/sys")             
    
