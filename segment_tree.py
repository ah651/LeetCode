'''
Segention Tree
'''

def build_tree(arr, tree, root_node, left, right):
    if left == right:
        tree[root_node] = arr[left]
    else:
        mid = (left + right) // 2
        left_node = 2 * root_node + 1
        right_node = 2* root_node + 2 
        build_tree(arr, tree, left_node, left, mid)
        build_tree(arr, tree, right_node, mid+1, right)
        tree[root_node] = tree[left_node] + tree[right_node]

def update_tree(arr, tree, root_node, left, right, idx, val):
    if left == right:
        arr[idx] = val
        tree[root_node] = val 
    else:
        mid = (left + right) // 2 
        left_node = 2 * root_node + 1
        right_node = 2 * root_node + 2
        if idx <= mid:
            update_tree(arr, tree, left_node, left, mid, idx, val)
        else:
            update_tree(arr, tree, right_node, mid, right, idx, val)
        tree[root_node] = tree[left_node] + tree[right_node]

def query_tree(arr, tree, root_node, left, right, L, R):
    if L > right or R < left:
        return 0 
    elif L <= left and right <= R:
        return tree[root_node] 
    # elif left == right:
    #     return tree[root_node]
    else:
        mid = (left + right) // 2 
        left_node = 2 * root_node + 1
        right_node = 2 * root_node + 2 
        left_sum = query_tree(arr, tree, left_node, left, mid, L, R)
        right_sum = query_tree(arr, tree, right_node, mid+1, right, L, R)
        return left_sum + right_sum

arr = [1, 4, 3, 7, 9, 3]
tree = [0 for i in range(3*len(arr))]
build_tree(arr, tree, 0, 0, len(arr)-1)
update_tree(arr, tree, 0, 0, len(arr)-1, 0, 10)
# for i in range(len(tree)):
#     print("node {} : {}".format(i, tree[i]))
r05 = query_tree(arr, tree, 0, 0, len(arr)-1, 0, 5)
print("r05 = {}".format(r05))
r04 = query_tree(arr, tree, 0, 0, len(arr)-1, 0, 4)
print("r04 = {}".format(r04))
r34 = query_tree(arr, tree, 0, 0, len(arr)-1, 3, 4)
print("r34 = {}".format(r34))


