from pyexpat import model
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

model_3 = defaultdict(lambda: defaultdict(lambda: 0))
model_4 = defaultdict(lambda: defaultdict(lambda: 0))
model_5 = defaultdict(lambda: defaultdict(lambda: 0))
model_6 = defaultdict(lambda: defaultdict(lambda: 0))
def tri_gram(tok): 
    for filename in os.listdir("./data"):
        fhand = open("./data/" + filename, "r")
        # Count frequency of co-occurance  
        for statement in fhand:
            if(statement.startswith("//")):
                continue
            tokens = nltk.word_tokenize(statement)
            for w1, w2, w3 in trigrams(tokens, pad_left = True, pad_right= True):
                model_3[(w1, w2)][w3] += 1
        fhand.close()
        # Let's transform the counts to probabilities
    for w1_w2 in model_3:
        total_count = float(sum(model_3[w1_w2].values()))
        for w3 in model_3[w1_w2]:
            model_3[w1_w2][w3] /= total_count    
    prediction(tok, model_3, 2)

def tetra_gram(tok): 
    for filename in os.listdir("./data"):
        fhand = open("./data/" + filename, "r")
        # Count frequency of co-occurance  
        for statement in fhand:
            if(statement.startswith("//")):
                continue
            tokens = nltk.word_tokenize(statement)
            for w1, w2, w3, w4 in ngrams(tokens, 4, pad_left = True, pad_right= True):
                model_4[(w1, w2, w3)][w4] += 1
        fhand.close()
        # Let's transform the counts to probabilities
    for w1_w3 in model_4:
        total_count = float(sum(model_4[w1_w3].values()))
        for w4 in model_4[w1_w3]:
            model_4[w1_w3][w4] /= total_count
    prediction(tok, model_4, 3)

def penta_gram(tok): 
    for filename in os.listdir("./data"):
        fhand = open("./data/" + filename, "r")
        # Count frequency of co-occurance  
        for statement in fhand:
            if(statement.startswith("//")):
                continue
            tokens = nltk.word_tokenize(statement)
            for w1, w2, w3, w4, w5 in ngrams(tokens, 5, pad_left = True, pad_right= True):
                model_5[(w1, w2, w3, w4)][w5] += 1
        fhand.close()
        # Let's transform the counts to probabilities
    for w1_w4 in model_5:
        total_count = float(sum(model_5[w1_w4].values()))
        for w5 in model_5[w1_w4]:
            model_5[w1_w4][w5] /= total_count
    prediction(tok, model_5, 4)

def hex_gram(tok):
    for filename in os.listdir("./data"):
        fhand = open("./data/" + filename, "r")
        # Count frequency of co-occurance  
        for statement in fhand:
            if(statement.startswith("//")):
                continue
            tokens = nltk.word_tokenize(statement)
            for w1, w2, w3, w4, w5, w6 in ngrams(tokens, 6, pad_left = True, pad_right = True):
                model_6[(w1, w2, w3, w4, w5)][w6] += 1
        fhand.close()
        # Let's transform the counts to probabilities
    for w1_w5 in model_6:
        total_count = float(sum(model_6[w1_w5].values()))
        for w6 in model_6[w1_w5]:
            model_6[w1_w5][w6] /= total_count
    prediction(tok, model_6, 5)

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
n = len(tokens)
match n:
    case 2:
        tri_gram(tokens)
    case 3:
        tri_gram(tokens[-2:]) 
        tetra_gram(tokens)
    case 4:
        tri_gram(tokens[-2:])
        tetra_gram(tokens[-3:])
        penta_gram(tokens)
    case 5:
        tri_gram(tokens[-2:])
        tetra_gram(tokens[-3:])
        penta_gram(tokens[-4:])
        hex_gram(tokens)
    case _:
        print("Not Supported yet")