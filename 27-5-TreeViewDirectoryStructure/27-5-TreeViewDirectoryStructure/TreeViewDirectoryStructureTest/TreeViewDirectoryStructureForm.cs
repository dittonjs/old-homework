    // Fig. 15.28: TreeViewDirectoryStructureForm.cs
    // Using TreeView to display directory structure.
    using System;
    using System.Windows.Forms;
    using System.IO;
    using System.Collections.Generic;
    using System.Linq;

    using System.Threading.Tasks;

    namespace TreeViewDirectoryStructure
    {
       // Form uses TreeView to display directory structure
   
       public partial class TreeViewDirectoryStructureForm : Form
       {
          string substringDirectory; // store last part of full path name
          List<string> dirs = new List<string>();
          List<string> files = new List<string>();
          string currentDir;
          string parentDir;
           // constructor
          public TreeViewDirectoryStructureForm()
          {
             InitializeComponent();
             inputTextBox.Text = Directory.GetCurrentDirectory();
          }

          // populate current node with subdirectories
          public void PopulateTreeView(
             string directoryValue, TreeNode parentNode )
          {
             // array stores all subdirectories in the directory
             string[] directoryArray =
                Directory.GetDirectories( directoryValue );

             // populate current node with subdirectories
             try
             {
                // check to see if any subdirectories are present
                if ( directoryArray.Length != 0 )
                {
                   // for every subdirectory, create new TreeNode,
                   // add as a child of current node and recursively
                   // populate child nodes with subdirectories
                   foreach ( string directory in directoryArray )
                   {
                      // obtain last part of path name from the full path 
                      // name by calling the GetFileNameWithoutExtension
                      // method of class Path
                     

                      // create TreeNode for current directory
                      TreeNode myNode = new TreeNode(directory);

                      // add current directory node to parent node
                      AddNode(parentNode, myNode);

                      // recursively populate every subdirectory
                      PopulateTreeView( directory, myNode );
                   }
                }
             }

             // catch exception
             catch ( UnauthorizedAccessException )
             {
                TreeNode node = new TreeNode("Access denied");
                AddNode(parentNode, node);
             }
          }

          public void FillDirectoryList(string directoryValue)
          {
              // array stores all subdirectories in the directory
              
              string[] directoryArray = Directory.GetDirectories(directoryValue);
              string[] filesArray = Directory.GetFiles(directoryValue);
              // populate current node with subdirectories
              try
              {
                  // check to see if any subdirectories are present
                  if (directoryArray.Length != 0)
                  {
                      // for every subdirectory, create new TreeNode,
                      // add as a child of current node and recursively
                      // populate child nodes with subdirectories
                      foreach (string directory in directoryArray)
                      {
                          dirs.Add(directory);
                      }
                      foreach (string file in filesArray)
                      {
                          files.Add(file);
                      }
                      foreach (string dir in dirs)
                      {
                          AddListView(dir);
                      }
                      foreach (string file in filesArray)
                      {
                          AddListView(file);
                      }
                  }
              }

              // catch exception
              catch (UnauthorizedAccessException)
              {
              
              }
          }

        private void AddListView(string dirName) {
            if (InvokeRequired)
            {
                Invoke(new MethodInvoker(() => AddListView(dirName)));
            }
            else {
                FileListView.Items.Add(dirName);
            }
        }
          private void AddNode(TreeNode parent, TreeNode node)
          {
              if (InvokeRequired)
                  Invoke(new MethodInvoker(() => AddNode(parent, node)));
              else
                  parent.Nodes.Add(node);
          }

          // handles enterButton click event
          private async void enterButton_Click( object sender, EventArgs e )
          {
             // clear all nodes
             directoryTreeView.Nodes.Clear();
             dirs.Clear();
             FileListView.Items.Clear();
             // check if the directory entered by user exists
             // if it does then fill in the TreeView,
             // if not display error MessageBox
             if ( Directory.Exists( inputTextBox.Text ) )
             {
                // add full path name to directoryTreeView 
                directoryTreeView.Nodes.Add( inputTextBox.Text );
                currentDir = inputTextBox.Text;
                Task task = Task.Run(() =>
                {
                    // insert subfolders
                    PopulateTreeView(
                       inputTextBox.Text, directoryTreeView.Nodes[0]);
                    FillDirectoryList(inputTextBox.Text);
                });

                await task;
             }
             // display error MessageBox if directory not found
             else
                MessageBox.Show( inputTextBox.Text + " could not be found.",
                   "Directory Not Found", MessageBoxButtons.OK,
                   MessageBoxIcon.Error );
          }

          private async void SearchButton_Click(object sender, EventArgs e)
          {
              string fileToSearch = currentDir + "\\" + SearchBox.Text;
              FileListView.Items.Clear();

              Task task = Task.Run(() =>
              {
                  var possibleFiles =
                   from file in files
                   where file.Contains(fileToSearch)
                   select file;
                  
                  var possibleDirs =
                   from dir in dirs
                   where dir.Contains(fileToSearch)
                   select dir;

                  foreach(string dir in possibleDirs){
                      AddListView(dir);
                  }

                  foreach (string file in possibleFiles)
                  {
                      AddListView(file);
                  }
              });

              await task;
              
          }

          private async void DeleteButton_Click(object sender, EventArgs e)
          {
              ListView.CheckedListViewItemCollection itemsToDelete = FileListView.CheckedItems;
                
              DialogResult result = MessageBox.Show("Are you sure you would like to delete the selected files. This will delete all files and folders inside if this is a directory. Delete?", "Delete Item",
               MessageBoxButtons.YesNo, MessageBoxIcon.Question);
              if (result == DialogResult.Yes) {
                  foreach (ListViewItem itemToDelete in itemsToDelete)
                  {
                      try
                      {
                          Task task = Task.Run(() =>
                          {

                              File.Delete(itemToDelete.Text);

                          });
                          await task;
                      }
                      catch (UnauthorizedAccessException exception) { 
                            
                      }
                     
                  }
                  
              
              }
          }


          private async void directoryTreeView_NodeMouseClick(object sender, TreeNodeMouseClickEventArgs e)
          {
              Console.WriteLine(e.Node.Text);
              if (Directory.Exists(e.Node.Text)) {
                  string next = e.Node.Text;
                  dirs.Clear();
                  FileListView.Items.Clear();
                  currentDir = next;
                  Task task = Task.Run(() =>
                  {
                      FillDirectoryList(next);
                  });

                  await task;
              }
          }

          private async void button1_Click(object sender, EventArgs e)
          {
              ListView.CheckedListViewItemCollection items = FileListView.CheckedItems;
              if (items.Count > 1)
              {
                  MessageBox.Show("Cannot Open more that one at a time");
              }
              else
              {
                  FileListView.Items.Clear();
                  dirs.Clear();
                  files.Clear();
                  
                  Task task = Task.Run(() =>
                  {
                      foreach (ListViewItem item in items)
                      {
                          currentDir = item.Text;
                          //FillDirectoryList(item.Text);
                          Console.WriteLine(item.Text);
                      }
                  });
                  await task;
              }
          }

       }
    }