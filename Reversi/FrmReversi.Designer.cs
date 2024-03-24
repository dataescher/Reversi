namespace Reversi {
	partial class FrmReversi {
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing) {
			if (disposing && (components != null)) {
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent() {
			this.components = new System.ComponentModel.Container();
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FrmReversi));
			this.IlImages = new System.Windows.Forms.ImageList(this.components);
			this.TmMorph = new System.Windows.Forms.Timer(this.components);
			this.GameContainer = new System.Windows.Forms.SplitContainer();
			this.LblWinner = new System.Windows.Forms.Label();
			this.PctCursor = new System.Windows.Forms.PictureBox();
			this.PctCurColor = new System.Windows.Forms.PictureBox();
			this.SsStatus = new System.Windows.Forms.StatusStrip();
			this.LblStatus = new System.Windows.Forms.ToolStripStatusLabel();
			this.LblPlaceholder = new System.Windows.Forms.ToolStripStatusLabel();
			this.LblProgress = new System.Windows.Forms.ToolStripStatusLabel();
			this.BtnExit = new System.Windows.Forms.Button();
			this.BtnNewGame = new System.Windows.Forms.Button();
			this.GpPlayer = new System.Windows.Forms.GroupBox();
			this.ChkBoth = new System.Windows.Forms.RadioButton();
			this.ChkNeither = new System.Windows.Forms.RadioButton();
			this.ChkBlack = new System.Windows.Forms.RadioButton();
			this.ChkWhite = new System.Windows.Forms.RadioButton();
			((System.ComponentModel.ISupportInitialize)(this.GameContainer)).BeginInit();
			this.GameContainer.Panel1.SuspendLayout();
			this.GameContainer.Panel2.SuspendLayout();
			this.GameContainer.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.PctCursor)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.PctCurColor)).BeginInit();
			this.SsStatus.SuspendLayout();
			this.GpPlayer.SuspendLayout();
			this.SuspendLayout();
			// 
			// IlImages
			// 
			this.IlImages.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("IlImages.ImageStream")));
			this.IlImages.TransparentColor = System.Drawing.Color.Transparent;
			this.IlImages.Images.SetKeyName(0, "blackchecker.png");
			this.IlImages.Images.SetKeyName(1, "redchecker.png");
			// 
			// TmMorph
			// 
			this.TmMorph.Interval = 10;
			this.TmMorph.Tick += new System.EventHandler(this.TmMorph_Tick);
			// 
			// GameContainer
			// 
			this.GameContainer.Dock = System.Windows.Forms.DockStyle.Fill;
			this.GameContainer.Location = new System.Drawing.Point(0, 0);
			this.GameContainer.Name = "GameContainer";
			this.GameContainer.Orientation = System.Windows.Forms.Orientation.Horizontal;
			// 
			// GameContainer.Panel1
			// 
			this.GameContainer.Panel1.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("GameContainer.Panel1.BackgroundImage")));
			this.GameContainer.Panel1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
			this.GameContainer.Panel1.Controls.Add(this.LblWinner);
			this.GameContainer.Panel1.Controls.Add(this.PctCursor);
			// 
			// GameContainer.Panel2
			// 
			this.GameContainer.Panel2.Controls.Add(this.PctCurColor);
			this.GameContainer.Panel2.Controls.Add(this.SsStatus);
			this.GameContainer.Panel2.Controls.Add(this.BtnExit);
			this.GameContainer.Panel2.Controls.Add(this.BtnNewGame);
			this.GameContainer.Panel2.Controls.Add(this.GpPlayer);
			this.GameContainer.Size = new System.Drawing.Size(650, 772);
			this.GameContainer.SplitterDistance = 650;
			this.GameContainer.TabIndex = 6;
			// 
			// LblWinner
			// 
			this.LblWinner.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.LblWinner.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
			this.LblWinner.Font = new System.Drawing.Font("Microsoft Sans Serif", 20.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.LblWinner.ForeColor = System.Drawing.Color.Black;
			this.LblWinner.Location = new System.Drawing.Point(217, 292);
			this.LblWinner.Name = "LblWinner";
			this.LblWinner.Size = new System.Drawing.Size(212, 62);
			this.LblWinner.Text = "Black Wins!!!";
			this.LblWinner.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			this.LblWinner.Visible = false;
			this.LblWinner.Click += new System.EventHandler(this.LblWinner_Click);
			// 
			// PctCursor
			// 
			this.PctCursor.BackColor = System.Drawing.Color.Transparent;
			this.PctCursor.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("PctCursor.BackgroundImage")));
			this.PctCursor.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
			this.PctCursor.Cursor = System.Windows.Forms.Cursors.Hand;
			this.PctCursor.Location = new System.Drawing.Point(0, 0);
			this.PctCursor.Name = "PctCursor";
			this.PctCursor.Size = new System.Drawing.Size(82, 82);
			this.PctCursor.TabIndex = 3;
			this.PctCursor.TabStop = false;
			this.PctCursor.Visible = false;
			this.PctCursor.Click += new System.EventHandler(this.PctCursor_Click);
			// 
			// PctCurColor
			// 
			this.PctCurColor.BackColor = System.Drawing.Color.MediumSeaGreen;
			this.PctCurColor.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
			this.PctCurColor.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.PctCurColor.Location = new System.Drawing.Point(283, 8);
			this.PctCurColor.Name = "PctCurColor";
			this.PctCurColor.Size = new System.Drawing.Size(80, 80);
			this.PctCurColor.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
			this.PctCurColor.TabIndex = 5;
			this.PctCurColor.TabStop = false;
			// 
			// SsStatus
			// 
			this.SsStatus.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
			this.LblStatus,
			this.LblPlaceholder,
			this.LblProgress});
			this.SsStatus.Location = new System.Drawing.Point(0, 93);
			this.SsStatus.Name = "SsStatus";
			this.SsStatus.Size = new System.Drawing.Size(650, 25);
			this.SsStatus.TabIndex = 4;
			this.SsStatus.Text = "statusStrip";
			// 
			// LblStatus
			// 
			this.LblStatus.Name = "LblStatus";
			this.LblStatus.Size = new System.Drawing.Size(39, 20);
			this.LblStatus.Text = "Status";
			// 
			// LblPlaceholder
			// 
			this.LblPlaceholder.AutoSize = false;
			this.LblPlaceholder.BorderStyle = System.Windows.Forms.Border3DStyle.Raised;
			this.LblPlaceholder.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.None;
			this.LblPlaceholder.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
			this.LblPlaceholder.Name = "LblPlaceholder";
			this.LblPlaceholder.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
			this.LblPlaceholder.Size = new System.Drawing.Size(474, 20);
			this.LblPlaceholder.Spring = true;
			// 
			// LblProgress
			// 
			this.LblProgress.BorderSides = ((System.Windows.Forms.ToolStripStatusLabelBorderSides)((((System.Windows.Forms.ToolStripStatusLabelBorderSides.Left | System.Windows.Forms.ToolStripStatusLabelBorderSides.Top)
			| System.Windows.Forms.ToolStripStatusLabelBorderSides.Right)
			| System.Windows.Forms.ToolStripStatusLabelBorderSides.Bottom)));
			this.LblProgress.Name = "LblProgress";
			this.LblProgress.Size = new System.Drawing.Size(122, 20);
			this.LblProgress.Text = "toolStripStatusLabel2";
			// 
			// BtnExit
			// 
			this.BtnExit.DialogResult = System.Windows.Forms.DialogResult.Cancel;
			this.BtnExit.Location = new System.Drawing.Point(144, 31);
			this.BtnExit.Name = "BtnExit";
			this.BtnExit.Size = new System.Drawing.Size(111, 30);
			this.BtnExit.TabIndex = 3;
			this.BtnExit.Text = "&Exit";
			this.BtnExit.UseVisualStyleBackColor = true;
			this.BtnExit.Click += new System.EventHandler(this.BtnExit_Click);
			// 
			// BtnNewGame
			// 
			this.BtnNewGame.Location = new System.Drawing.Point(16, 31);
			this.BtnNewGame.Name = "BtnNewGame";
			this.BtnNewGame.Size = new System.Drawing.Size(111, 30);
			this.BtnNewGame.TabIndex = 2;
			this.BtnNewGame.Text = "&New Game";
			this.BtnNewGame.UseVisualStyleBackColor = true;
			this.BtnNewGame.Click += new System.EventHandler(this.BtnNewGame_Click);
			// 
			// GpPlayer
			// 
			this.GpPlayer.Controls.Add(this.ChkBoth);
			this.GpPlayer.Controls.Add(this.ChkNeither);
			this.GpPlayer.Controls.Add(this.ChkBlack);
			this.GpPlayer.Controls.Add(this.ChkWhite);
			this.GpPlayer.Location = new System.Drawing.Point(385, 12);
			this.GpPlayer.Name = "GpPlayer";
			this.GpPlayer.Size = new System.Drawing.Size(244, 68);
			this.GpPlayer.TabIndex = 0;
			this.GpPlayer.TabStop = false;
			this.GpPlayer.Text = "Human Player Color";
			// 
			// ChkBoth
			// 
			this.ChkBoth.AutoSize = true;
			this.ChkBoth.Location = new System.Drawing.Point(94, 19);
			this.ChkBoth.Name = "ChkBoth";
			this.ChkBoth.Size = new System.Drawing.Size(47, 17);
			this.ChkBoth.TabIndex = 3;
			this.ChkBoth.Text = "Both";
			this.ChkBoth.UseVisualStyleBackColor = true;
			// 
			// ChkNeither
			// 
			this.ChkNeither.AutoSize = true;
			this.ChkNeither.Location = new System.Drawing.Point(94, 42);
			this.ChkNeither.Name = "ChkNeither";
			this.ChkNeither.Size = new System.Drawing.Size(59, 17);
			this.ChkNeither.TabIndex = 2;
			this.ChkNeither.Text = "Neither";
			this.ChkNeither.UseVisualStyleBackColor = true;
			this.ChkNeither.CheckedChanged += new System.EventHandler(this.ChkNeither_CheckedChanged);
			// 
			// ChkBlack
			// 
			this.ChkBlack.AutoSize = true;
			this.ChkBlack.Checked = true;
			this.ChkBlack.Location = new System.Drawing.Point(6, 19);
			this.ChkBlack.Name = "ChkBlack";
			this.ChkBlack.Size = new System.Drawing.Size(52, 17);
			this.ChkBlack.TabIndex = 1;
			this.ChkBlack.TabStop = true;
			this.ChkBlack.Text = "&Black";
			this.ChkBlack.UseVisualStyleBackColor = true;
			this.ChkBlack.CheckedChanged += new System.EventHandler(this.ChkBlack_CheckedChanged);
			// 
			// ChkWhite
			// 
			this.ChkWhite.AutoSize = true;
			this.ChkWhite.Location = new System.Drawing.Point(6, 42);
			this.ChkWhite.Name = "ChkWhite";
			this.ChkWhite.Size = new System.Drawing.Size(53, 17);
			this.ChkWhite.TabIndex = 0;
			this.ChkWhite.Text = "&White";
			this.ChkWhite.UseVisualStyleBackColor = true;
			this.ChkWhite.CheckedChanged += new System.EventHandler(this.ChkWhite_CheckedChanged);
			// 
			// FrmReversi
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.BackColor = System.Drawing.SystemColors.Control;
			this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
			this.ClientSize = new System.Drawing.Size(650, 772);
			this.ControlBox = false;
			this.Controls.Add(this.GameContainer);
			this.DoubleBuffered = true;
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
			this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
			this.MaximizeBox = false;
			this.MinimizeBox = false;
			this.Name = "FrmReversi";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "Reversi";
			this.Load += new System.EventHandler(this.FrmReversi_Load);
			this.GameContainer.Panel1.ResumeLayout(false);
			this.GameContainer.Panel2.ResumeLayout(false);
			this.GameContainer.Panel2.PerformLayout();
			((System.ComponentModel.ISupportInitialize)(this.GameContainer)).EndInit();
			this.GameContainer.ResumeLayout(false);
			((System.ComponentModel.ISupportInitialize)(this.PctCursor)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.PctCurColor)).EndInit();
			this.SsStatus.ResumeLayout(false);
			this.SsStatus.PerformLayout();
			this.GpPlayer.ResumeLayout(false);
			this.GpPlayer.PerformLayout();
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.ImageList IlImages;
		private System.Windows.Forms.Timer TmMorph;
		private System.Windows.Forms.PictureBox PctCursor;
		private System.Windows.Forms.SplitContainer GameContainer;
		private System.Windows.Forms.StatusStrip SsStatus;
		private System.Windows.Forms.ToolStripStatusLabel LblStatus;
		private System.Windows.Forms.Button BtnExit;
		private System.Windows.Forms.Button BtnNewGame;
		private System.Windows.Forms.GroupBox GpPlayer;
		private System.Windows.Forms.RadioButton ChkBlack;
		private System.Windows.Forms.RadioButton ChkWhite;
		private System.Windows.Forms.RadioButton ChkNeither;
		private System.Windows.Forms.RadioButton ChkBoth;
		private System.Windows.Forms.PictureBox PctCurColor;
		private System.Windows.Forms.Label LblWinner;
		private System.Windows.Forms.ToolStripStatusLabel LblPlaceholder;
		private System.Windows.Forms.ToolStripStatusLabel LblProgress;

	}
}

