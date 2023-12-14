import hmmlearn.hmm as hmm
import numpy as np
import os

def get_arbid_seq(filepath):
  seq_li = list()
  with open(filepath, 'r') as f:
    lines = f.readlines()
    for line in lines:
#seq = np.append(seq, line.split('\t')[1]) 
      seq_li.append(line.split('\t')[1])
      arbID_seq = np.fromiter((int(x, 16) for x in seq_li), dtype=np.uint16)
  #print(arbID_seq)
  return arbID_seq

def change_sequence_by_hamming_distance(window, hamming_seq, threshold):
  modified_window = window.copy()
  for i, value in enumerate(window):
    if np.abs(value - hamming_seq[i]) <= threshold:
      modified_window[i] = hamming_seq[i]
  return modified_window

def get_split_arbid_seq_by_wnd(arbidseq, wndsize=5):
  splited = np.array([])
  cnt = 0
  for i in range(np.size(arbidseq)-wndsize+1):
    splited = np.append(splited, arbidseq[i:i+wndsize]); cnt+=1
  splited = np.reshape(splited, (cnt,wndsize))
  return splited


train_arbID_seq = get_arbid_seq("C:\\Users\\SCHCSRC\\Desktop\\train_s.txt")
tr_set = get_split_arbid_seq_by_wnd(train_arbID_seq)
test_arbID_seq = get_arbid_seq("C:\\Users\\SCHCSRC\\Desktop\\test_s.txt")
te_set = get_split_arbid_seq_by_wnd(test_arbID_seq)



# 해당 부분에서 해밍 거리 시퀀스를 생성 및 전달
hamming_seq = ...
tr_set = get_split_arbid_seq_by_wnd(train_arbID_seq, wndsize=5, hamming_seq=hamming_seq)
te_set = get_split_arbid_seq_by_wnd(test_arbID_seq, wndsize=5, hamming_seq=hamming_seq)

h = hmm.GaussianHMM(2)
print('--------------')
h.fit(tr_set)
print(h.score(tr_set)) #sum of log probability
print(h.score(te_set))
print('--------------')
print(h.startprob_) #init prob
print(h.transmat_) #state transition prob