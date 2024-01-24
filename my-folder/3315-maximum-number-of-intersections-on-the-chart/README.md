<p>There is a line chart consisting of <code>n</code> points connected by line segments. You are given a <strong>1-indexed</strong> integer array <code>y</code>. The <code>k<sup>th</sup></code> point has coordinates <code>(k, y[k])</code>. There are no horizontal lines; that is, no two consecutive points have the same y-coordinate.</p>

<p>We can draw an infinitely long horizontal line. Return <em>the <strong>maximum</strong> number of points of intersection of the line with the chart</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<strong><img alt="" src="https://assets.leetcode.com/static_assets/others/20231208-020549.jpeg" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; height: 217px; width: 600px;" /></strong>

<pre>
<strong>Input:</strong> y = [1,2,1,2,1,3,2]
<strong>Output:</strong> 5
<strong>Explanation:</strong> As you can see in the image above, the line y = 1.5 has 5 intersections with the chart (in red crosses). You can also see the line y = 2 which intersects the chart in 4 points (in red crosses). It can be shown that there is no horizontal line intersecting the chart at more than 5 points. So the answer would be 5.
</pre>

<p><strong class="example">Example 2:</strong></p>
<strong><img alt="" src="https://assets.leetcode.com/static_assets/others/20231208-020557.jpeg" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 400px; height: 404px;" /></strong>

<pre>
<strong>Input:</strong> y = [2,1,3,4,5]
<strong>Output:</strong> 2
<strong>Explanation:</strong> As you can see in the image above, the line y = 1.5 has 2 intersections with the chart (in red crosses). You can also see the line y = 2 which intersects the chart in 2 points (in red crosses). It can be shown that there is no horizontal line intersecting the chart at more than 2 points. So the answer would be 2.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= y.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= y[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>y[i] != y[i + 1]</code> for <code>i</code> in range <code>[1, n - 1]</code></li>
</ul>
