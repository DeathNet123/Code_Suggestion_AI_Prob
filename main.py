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
for idx in range(0, 1):    
    for filename in os.listdir("./clean_data"):
        fhand = open("./clean_data/" + filename, "r")
        # Count frequency of co-occurance  
        for sentence in fhand:
            if(sentence.startswith("//")):
                continue
            tokens = nltk.word_tokenize(sentence)
            for w1, w2, w3 in trigrams(tokens, pad_right=True, pad_left=True):
                model_3[(w1, w2)][w3] += 1

        # Let's transform the counts to probabilities
        for w1_w2 in model_3:
            total_count = float(sum(model_3[w1_w2].values()))
            for w3 in model_3[w1_w2]:
                model_3[w1_w2][w3] /= total_count

for idx in range(0, 1):    
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
        for w1_w2 in model_6:
            total_count = float(sum(model_6[w1_w2].values()))
            for w3 in model_6[w1_w2]:
                model_6[w1_w2][w3] /= total_count

    text = [sys.argv[1], sys.argv[2]]
    sentence_finished = False
idx = 0
while idx < 10:    
    while not sentence_finished:
        # select a random probability threshold  
        r = random.random()
        accumulator = .0
        for word in model_3[tuple(text[-2:])].keys():
            accumulator += model_3[tuple(text[-2:])][word]
            # select words that are above the probability threshold
            if accumulator >= r:
                text.append(word)
                break
        if text[-2:] == [None, None]:
            sentence_finished = True
    
    print (' '.join([t for t in text if t]))

    # starting words
    text = [sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4], sys.argv[5]]
    sentence_finished = 50
    while sentence_finished != 0:
        # select a random probability threshold  
        r = random.random()
        accumulator = .0
        for word in model_6[tuple(text[-5:])].keys():
            accumulator += model_6[tuple(text[-5:])][word]
            # select words that are above the probability threshold
            if accumulator >= r:
                text.append(word)
                break
        sentence_finished = sentence_finished - 1
    
    print (' '.join([t for t in text if t]))
    idx = idx + 1

