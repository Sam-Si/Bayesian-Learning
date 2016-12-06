<img src="https://raw.githubusercontent.com/matiassingers/awesome-readme/master/icon.png" align="right" />
# Bayesian-Learning

Bayesian inference is a method of statistical inference in which Bayes' theorem is used to update the probability for a hypothesis as more evidence or information becomes available. Bayesian inference is an important technique in statistics, and especially in mathematical statistics.

## TASK

The task is classifying windows cropped from images as containing a face or not. This is a
basic step in face detection, where a window is scanned over the image, and for each window
location, the classifier has to answer the question of whether a face is present (binary
classification).

The data file is provided to you and it contains training & test patches and binary labels,
where 0 corresponds to 'non-face' and 1 corresponds to 'face'. The patches themselves are
higher-resolution than the digit images, and each pixel value is either '#', corresponding to an
edge being found at that location, or ' ', corresponding to a non-edge pixel.

* You have to train a Naive Bayes classifier that distinguish faces from non-faces. In
your report, describe the accuracy, any interesting experimental settings (smoothing
constant, etc.) and give the confusion matrix for this task, which should have four
entries. Also show a few interesting examples of false positives (non-faces classified
as faces) and false negatives (faces classified as non-faces).

## Pre-processing Data

* Each Face in the data file spans 70 rows and 60 cols. For every face, we create a vector of
size 70*60 that stores 1 for a ’#’ encountered and a 0 for a ’ ’ encountered. We store this
vector in a new file.

 NOTE: All the filenames starting with 'm' are modified files.

*  A new line is added once we have read 70 rows from the original file. This way, a single row
in the modified file contains the data regarding one face.
* The same is done even for the test file.
Training the Classifier and Testing Data
* The training data is read from the modified file, and for each column, over every row, we see
if the binary value assigned to that column matches that of the result for that row. We keep
count of the sequence of matching, be it 0 0, 0 1, 1 0, 1 1. Thus, we calculate the probability of
each of these sequences, as p00, p01, p10, p11.
* This way, we end up with the count of each of the 4 possible sequences for every column.
* The test data is also read from a modified file. Now, every row can either yield a positive or
a negative result. We calculate the probability of both hypotheses, and which ever is greater,
we select that.
* In order to calculate the probabilities, we assume that the row has a positive result, and for
every column, we find the sequence. If the column has a value of 0, then it is a 0 1 sequence,
else it is a 1 1 sequence. If a column is a 0 1 sequence, it is taken to have a probability value
as calculated above for the training data set (the p01 value and the p11 value). The probability
of the row having a positive result is thus the product of the probabilities of the 4200
columns and the number of positives observed in the training set. Likewise, the probability of
a row having a negative result is calculated, only in this case, every column can have a probability
of p00 or p10. The prediction is that hypotheses which has a greater probability.


## Results

* The accuracy is calculated based on the number of true positives and true negatives as per
the predictions. It is found to be 88.6667% for the given test set.
* The Confusion Matrix is as follows
  * 70 True Negatives
  * 63 True Positives
  * 10 False Negatives
  * 7 False Positives
