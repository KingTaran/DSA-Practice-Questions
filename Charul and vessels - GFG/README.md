# Charul and vessels
## Easy 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Charul has been given a task by Ishaan. He challenges him to fill a large container of capacity K liters. Charul has N vessels with him with different capacities.<br>
The capacities of the vessels are given by an array A. The condition is that the container should be filled up to the brim but no water&nbsp;should be wasted in overflowing. Also, the vessels can't be filled partially.<br>
Determine if Charul can fill up the container with the given conditions or not.<br>
Assume that Charul has an unlimited supply of water.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>â€‹Input :</strong> arr[ ] = {6, 3, 4, 2, 1} and K = 20
<strong>Output :</strong> 1
<strong>Explanation:</strong>
The container can be filled in the following manner :&nbsp;
Add water using the 6 litre vessel 3 times :
Container filled upto 18 litres
Add water using the 2 litre vessel 1 time : 
Container filled upto 20 litres
</span></pre>

<p><br>
<span style="font-size:18px"><strong>â€‹Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input :</strong> arr[ ] = {2, 4, 3} and K = 15 <strong>
Output :</strong>  1</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function <strong>vessel()</strong> that takes an array <strong>(arr)</strong>, sizeOfArray <strong>(n)</strong>, an integer <strong>K,&nbsp;</strong>and return the array return <strong>true</strong> if it is possible else return <strong>false</strong>. The driver code takes care of the printing.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N*K).<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(X). where X is the maximum element in an array.</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints :</strong>&nbsp;<br>
1 ≤ N ≤ 100<br>
1 ≤ K ≤ 10<sup>3</sup><br>
1 ≤ A[i] ≤ 100</span></p>
 <p></p>
            </div>