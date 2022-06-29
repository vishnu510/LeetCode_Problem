# Jumping Caterpillars
## Easy 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given <strong>N</strong> leaves numbered from <strong>1 to N</strong> . A caterpillar at leaf <strong>1</strong>, jumps from leaf to leaf in multiples of A<sub>j</sub> (A<sub>j</sub>, 2A<sub>j</sub>, 3A<sub>j</sub>).<br>
j is specific to the caterpillar. Whenever a caterpillar reaches a leaf, it eats it a little bit.. You have to find out how many leaves, from <strong>1 to N</strong>, are left uneaten after all<strong> K</strong>&nbsp;caterpillars have reached the end. Each caterpillar has its own jump factor denoted by <strong>A<sub>j</sub></strong>, and each caterpillar starts at leaf number 1. </span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N=10 K=3
arr[] = {2, 3, 5} 
<strong>Output:</strong> 2
<strong>Explanation</strong>: The leaves eaten by the first 
caterpillar are (2, 4, 6, 8, 10). The leaves 
eaten by the second caterpilllar are (3, 6, 9).
The leaves eaten by the third caterpilllar 
are (5, 10). Ultimately, the uneaten leaves are 
1, 7 and their number is 2.</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
Since this is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function <strong>uneatenLeaves</strong>() that takes <strong>array arr,&nbsp;integer N, and&nbsp;integer K</strong>&nbsp;as parameters and returns the number of uneaten leaves.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N<sup>2</sup>).<br>
<strong>Expected Auxiliary Space:</strong> O(N).</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 10<sup>4</sup></span></p>
 <p></p>
            </div>