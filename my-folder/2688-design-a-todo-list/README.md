<p>Design a Todo List Where users can add <strong>tasks</strong>, mark them as <strong>complete</strong>, or get a list of pending tasks. Users can also add <strong>tags</strong> to tasks and can filter the tasks by certain tags.</p>

<p>Implement the <code>TodoList</code> class:</p>

<ul>
	<li><code>TodoList()</code> Initializes the object.</li>
	<li><code>int addTask(int userId, String taskDescription, int dueDate, List&lt;String&gt; tags)</code> Adds a task for the user with the ID <code>userId</code> with a due date equal to <code>dueDate</code> and a list of tags attached to the task. The return value is the ID of the task. This ID starts at <code>1</code> and is <strong>sequentially</strong> increasing. That is, the first task&#39;s id should be <code>1</code>, the second task&#39;s id should be <code>2</code>, and so on.</li>
	<li><code>List&lt;String&gt; getAllTasks(int userId)</code> Returns a list of all the tasks not marked as complete for the user with ID <code>userId</code>, ordered by the due date. You should return an empty list if the user has no uncompleted tasks.</li>
	<li><code>List&lt;String&gt; getTasksForTag(int userId, String tag)</code> Returns a list of all the tasks that are not marked as complete for the user with the ID <code>userId</code> and have <code>tag</code> as one of their tags, ordered by their due date. Return an empty list if no such task exists.</li>
	<li><code>void completeTask(int userId, int taskId)</code> Marks the task with the ID <code>taskId</code> as completed only if the task exists and the user with the ID <code>userId</code> has this task, and it is uncompleted.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input</strong>
[&quot;TodoList&quot;, &quot;addTask&quot;, &quot;addTask&quot;, &quot;getAllTasks&quot;, &quot;getAllTasks&quot;, &quot;addTask&quot;, &quot;getTasksForTag&quot;, &quot;completeTask&quot;, &quot;completeTask&quot;, &quot;getTasksForTag&quot;, &quot;getAllTasks&quot;]
[[], [1, &quot;Task1&quot;, 50, []], [1, &quot;Task2&quot;, 100, [&quot;P1&quot;]], [1], [5], [1, &quot;Task3&quot;, 30, [&quot;P1&quot;]], [1, &quot;P1&quot;], [5, 1], [1, 2], [1, &quot;P1&quot;], [1]]
<strong>Output</strong>
[null, 1, 2, [&quot;Task1&quot;, &quot;Task2&quot;], [], 3, [&quot;Task3&quot;, &quot;Task2&quot;], null, null, [&quot;Task3&quot;], [&quot;Task3&quot;, &quot;Task1&quot;]]

<strong>Explanation</strong>
TodoList todoList = new TodoList();
todoList.addTask(1, &quot;Task1&quot;, 50, []); // return 1. This adds a new task for the user with id 1.
todoList.addTask(1, &quot;Task2&quot;, 100, [&quot;P1&quot;]); // return 2. This adds another task for the user with id 1.
todoList.getAllTasks(1); // return [&quot;Task1&quot;, &quot;Task2&quot;]. User 1 has two uncompleted tasks so far.
todoList.getAllTasks(5); // return []. User 5 does not have any tasks so far.
todoList.addTask(1, &quot;Task3&quot;, 30, [&quot;P1&quot;]); // return 3. This adds another task for the user with id 1.
todoList.getTasksForTag(1, &quot;P1&quot;); // return [&quot;Task3&quot;, &quot;Task2&quot;]. This returns the uncompleted tasks that have the tag &quot;P1&quot; for the user with id 1.
todoList.completeTask(5, 1); // This does nothing, since task 1 does not belong to user 5.
todoList.completeTask(1, 2); // This marks task 2 as completed.
todoList.getTasksForTag(1, &quot;P1&quot;); // return [&quot;Task3&quot;]. This returns the uncompleted tasks that have the tag &quot;P1&quot; for the user with id 1.
                                  // Notice that we did not include &quot;Task2&quot; because it is completed now.
todoList.getAllTasks(1); // return [&quot;Task3&quot;, &quot;Task1&quot;]. User 1 now has 2 uncompleted tasks.

</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= userId, taskId, dueDate &lt;= 100</code></li>
	<li><code>0 &lt;= tags.length &lt;= 100</code></li>
	<li><code>1 &lt;= taskDescription.length &lt;= 50</code></li>
	<li><code>1 &lt;= tags[i].length, tag.length &lt;= 20</code></li>
	<li>All <code>dueDate</code> values are unique.</li>
	<li>All the strings consist of lowercase and uppercase English letters and digits.</li>
	<li>At most <code>100</code> calls will be made for each method.</li>
</ul>
