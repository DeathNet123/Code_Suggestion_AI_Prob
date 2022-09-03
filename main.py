from nltk.corpus import reuters
from nltk import bigrams, trigrams, ngrams
from collections import Counter, defaultdict
import nltk
import random
import os
import sys
import sctokenizer
# nltk.download('reuters')
# nltk.download('punkt')

# Create a placeholder for model_3
model_3 = defaultdict(lambda: defaultdict(lambda: 0))
model_6 = defaultdict(lambda: defaultdict(lambda: 0))

#MODEL 3 trigram.........    
for filename in os.listdir("./clean_data"):
    fhand = open("./clean_data/" + filename, "r")
        # Count frequency of co-occurance  
    for sentence in fhand:
        if(sentence.startswith("//")):
            continue
        tokens = nltk.word_tokenize(sentence)
        for w1, w2, w3, w4 in ngrams(tokens, 4):
            model_3[(w1, w2)][w4] += 1
        # Let's transform the counts to probabilities
    for w1_w3 in model_3:
        total_count = float(sum(model_3[w1_w3].values()))
        for w4 in model_3[w1_w3]:
            model_3[w1_w3][w4] /= total_count
#**********************************************************************
#Model 6 hexgram....
for filename in os.listdir("./clean_data"):
    fhand = open("./clean_data/" + filename, "r")
        # Count frequency of co-occurance  
    for sentence in fhand:
        if(sentence.startswith("//")):
            continue
        tokens = nltk.word_tokenize(sentence)
        for w1, w2, w3, w4, w5, w6 in ngrams(tokens, 6):
            model_6[(w1, w2, w3, w4, w5)][w6] += 1

        # Let's transform the counts to probabilities
    for w1_w5 in model_6:
        total_count = float(sum(model_6[w1_w5].values()))
        for w6 in model_6[w1_w5]:
            model_6[w1_w5][w6] /= total_count
#*********************************************

#model 3 predictions
text = [sys.argv[1], sys.argv[2], sys.argv[3]]

idx = 0
while idx < 10:
    sentence_finished = 50    
    while sentence_finished != 0:
        # select a random probability threshold  
        r = random.random()
        accumulator = .0
        for word in model_3[tuple(text[-3:])].keys():
            accumulator += model_3[tuple(text[-3:])][word]
            # select words that are above the probability threshold
            if accumulator >= r:
                text.append(word)
                break
        sentence_finished = sentence_finished - 1
    
    print (' '.join([t for t in text if t]))
#***********************************************
#Model 6..............
    # # starting words
    # text = [sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4], sys.argv[5]]
    # sentence_finished = 50
    # while sentence_finished != 0:
    #     # select a random probability threshold  
    #     r = random.random()
    #     accumulator = .0
    #     for word in model_6[tuple(text[-5:])].keys():
    #         accumulator += model_6[tuple(text[-5:])][word]
    #         # select words that are above the probability threshold
    #         if accumulator >= r:
    #             text.append(word)
    #             break
    #     sentence_finished = sentence_finished - 1
    
    # print (' '.join([t for t in text if t]))
    idx = idx + 1
#**********************************************************

