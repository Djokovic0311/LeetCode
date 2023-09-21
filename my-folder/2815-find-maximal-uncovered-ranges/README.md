<p>You are given&nbsp;an integer <code>n</code>&nbsp;which is the length of a <strong>0-indexed</strong> array <code>nums</code>, and a <strong>0-indexed</strong> 2D-array <code>ranges</code>, which is a list of sub-ranges of <code>nums</code>&nbsp;(sub-ranges may <strong>overlap</strong>).</p>

<p>Each row <code>ranges[i]</code> has exactly 2 cells:</p>

<ul>
	<li><code>ranges[i][0]</code>, which shows the start of the i<sup>th</sup> range (inclusive)</li>
	<li><code>ranges[i][1]</code>, which shows the end of the i<sup>th</sup> range (inclusive)</li>
</ul>

<p>These ranges cover some cells of <code>nums</code>&nbsp;and leave&nbsp;some cells uncovered. Your task is to find all of the <b>uncovered </b>ranges with <strong>maximal</strong> length.</p>

<p>Return <em>a 2D-array </em><code>answer</code><em> of the uncovered ranges, <strong>sorted</strong> by the starting point in <strong>ascending order</strong>.</em></p>

<p>By all of the&nbsp;<strong>uncovered</strong> ranges with <strong>maximal</strong> length, we mean satisfying two conditions:</p>

<ul>
	<li>Each uncovered cell should belong to <strong>exactly</strong> one sub-range</li>
	<li>There should <strong>not exist</strong>&nbsp;two ranges (l<sub>1</sub>, r<sub>1</sub>) and (l<sub>2</sub>, r<sub>2</sub>) such that r<sub>1 </sub>+ 1 = l<sub>2</sub></li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 10, ranges = [[3,5],[7,8]]
<strong>Output:</strong> [[0,2],[6,6],[9,9]]
<strong>Explanation:</strong> The ranges (3, 5) and (7, 8) are covered, so if we simplify the array nums to a binary array where 0 shows an uncovered cell and 1 shows a covered cell, the array becomes [0,0,0,1,1,1,0,1,1,0] in which we can observe that the ranges (0, 2), (6, 6) and (9, 9) aren&#39;t covered.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 3, ranges = [[0,2]]
<strong>Output:</strong> []
<strong>Explanation: </strong>In this example, the whole of the array nums is covered and there are no uncovered cells so the output is an empty array.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> n = 7, ranges = [[2,4],[0,3]]
<strong>Output:</strong> [[5,6]]
<strong>Explanation:</strong> The ranges (0, 3) and (2, 4) are covered, so if we simplify the array nums to a binary array where 0 shows an uncovered cell and 1 shows a covered cell, the array becomes [1,1,1,1,1,0,0] in which we can observe that the range (5, 6) is uncovered.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;=&nbsp;10<sup>9</sup></code></li>
	<li><code>0 &lt;= ranges.length &lt;= 10<sup>6</sup></code></li>
	<li><code>ranges[i].length = 2</code></li>
	<li><code>0 &lt;= ranges[i][j] &lt;= n - 1</code></li>
	<li><code>ranges[i][0] &lt;=&nbsp;ranges[i][1]</code></li>
</ul>
