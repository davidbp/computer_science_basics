import pyspark
from pyspark.sql import SparkSession
from pyspark.ml.feature import NGram
from pyspark import SparkContext
import nltk
from nltk.corpus import gutenberg
import sys
import time
import random
#import platform
#print("\n\nPython version:", platform.python_version(),"\n\n")

def tokenize_and_compute_ngrams(x, n_words = 3):
    x_tokens = nltk.word_tokenize(x)
    x_ngrams = list(nltk.ngrams(x_tokens, n_words))
    return x_ngrams


if __name__ == "__main__":
    #sc = SparkContext("local")  # This uses 1 CORE

    sc = SparkContext()          # This uses ALL cores
    t0 = time.time()
    
    #### Tuneanable params ####
    scale_factor = 1
    use_gutenberg = False

    ## params used only if use_gutenberg=false
    n_words_per_text = 500*10
    n_texts          = 1000

    n_words_per_text = 50*10
    n_texts          = 500
    ###########################
    
    texts = []
    
    if use_gutenberg:
        nltk.download("gutenberg")
        nltk.download("punkt")
        for file_id in gutenberg.fileids():
            texts.append(gutenberg.raw(file_id))
    else:
        # Generate random words of from 2 to 9 letters and make a text of n
        for i in range(n_texts):
            text = ''
            for w in range(n_words_per_text):
                text += ''.join(random.choice('abcdefghijklmnopqrstuvwxyz') for _ in range(random.randint(2,9))) 
            texts.append(text)
    
    #for i in range(scale_factor):
    #    texts += texts
    
    print("\n\n\t- Number of files {} \n".format(len(texts)))
    texts_size = sum([sys.getsizeof(x) for x in texts])
    print("\t- Size of the data: {} MB\n\n".format(texts_size*1e-6))
    
    ####################################################################
    rdd           = sc.parallelize(texts)
    rdd_tokenized = rdd.map(tokenize_and_compute_ngrams)
    #import pdb;pdb.set_trace()
    result        = rdd_tokenized.collect()
    print("\n\n\t- Total time tanken {} sec. \n".format(abs(time.time()-t0)))

