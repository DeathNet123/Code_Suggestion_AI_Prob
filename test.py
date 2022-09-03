from nltk.corpus import reuters
from nltk import bigrams, trigrams, ngrams
from collections import Counter, defaultdict
import nltk
import random
import os
import sys
import sctokenizer

words = tuple()
model_n = defaultdict(lambda: defaultdict(lambda: 0))
def n_gram(tok):
    for filename in os.listdir("./clean_data"):
        fhand = open("./clean_data/" + filename, "r")
        # Count frequency of co-occurance  
        for statement in fhand:
            if(statement.startswith("//")):
                continue
            tokens = nltk.word_tokenize(statement)
            for words in ngrams(tokens, len(tok) + 1, pad_left = True, pad_right = True):
                model_n[(words[: len(tok)])][words[len(tok) - 1]] += 1
        fhand.close()
        # Let's transform the counts to probabilities
    for w1_wn_1 in model_n:
        total_count = float(sum(model_n[w1_wn_1].values()))
        for wn in model_n[w1_wn_1]:
            model_n[w1_wn_1][wn] /= total_count
    prediction(tok, model_n, len(tok) - 1)

def prediction(tokens, model, n):
    text = [*tokens]
    sentence_finished = False
    while not sentence_finished :
        # select a random probability threshold  
        r = random.random()
        accumulator = .0
        for word in model[tuple(text[-n:])].keys():
            accumulator = model[tuple(text[-n:])][word]
            # select words that are above the probability threshold
            if accumulator >= r:
                text.append(word)
                break
        if text[-2:] == [None, None]:
            sentence_finished = True
    print (' '.join([t for t in text if t]))
    
statement = input("Enter the statement to complete : ")
tokens = nltk.word_tokenize(statement)
n_gram(tokens)