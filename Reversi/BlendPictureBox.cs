// BlendPictureBox.cs
// Variant of PictureBox control which allows blending of two image files
// Programmed by Jonathan Feucht, 2015

using System;
using System.Drawing;
using System.Drawing.Imaging;
using System.Windows.Forms;

namespace Reversi {
	internal class BlendPictureBox : PictureBox {
		private Bitmap mImg1;
		private Bitmap mImg2;
		private Single mRotate;
		private Single mBlend;
		private Boolean mEmpty;

		public BlendPictureBox() {
			SetStyle(ControlStyles.AllPaintingInWmPaint | ControlStyles.UserPaint | ControlStyles.OptimizedDoubleBuffer, true);
		}

		public Single RotationAngle {
			get => mRotate;
			set {
				mRotate = value;
				Invalidate();
			}
		}

		public Bitmap Image1 {
			get => mImg1;
			set {
				mImg1 = RotateImage(value, mRotate);
				Invalidate();
			}
		}

		public Bitmap Image2 {
			get => mImg2;
			set {
				mImg2 = RotateImage(value, mRotate);
				//mImg2 = value;
				Invalidate();
			}
		}

		public Single Blend {
			get => mBlend;
			set {
				mBlend = value;
				Invalidate();
			}
		}

		public Boolean Empty {
			get => mEmpty;
			set {
				mEmpty = value;
				Invalidate();
			}
		}

		protected override void OnPaint(PaintEventArgs e) {
			if (mImg1 == null || mImg2 == null || mEmpty) {
				e.Graphics.FillRectangle(new SolidBrush(BackColor), new Rectangle(0, 0, Width, Height));
			} else {
				Rectangle rc = new(0, 0, Width, Height);
				ColorMatrix cm = new();
				ImageAttributes ia = new();

				cm.Matrix33 = mBlend;
				ia.SetColorMatrix(cm);
				e.Graphics.DrawImage(mImg2, rc, 0, 0, mImg2.Width, mImg2.Height, GraphicsUnit.Pixel, ia);
				cm.Matrix33 = 1F - mBlend;
				ia.SetColorMatrix(cm);

				e.Graphics.DrawImage(mImg1, rc, 0, 0, mImg1.Width, mImg1.Height, GraphicsUnit.Pixel, ia);
			}
			base.OnPaint(e);
		}

		private Bitmap RotateImage(Bitmap b, Single angle) {
			// Create a new empty bitmap to hold rotated image
			Bitmap returnBitmap = new(b.Width, b.Height);
			// Make a graphics object from the empty bitmap
			Graphics g = Graphics.FromImage(returnBitmap);
			Rectangle srect = new(0, 0, b.Width, b.Height);
			// Move rotation point to center of image
			g.TranslateTransform((Single)b.Width / 2, (Single)b.Height / 2);
			// Rotate
			g.RotateTransform(angle);
			// Move image back
			g.TranslateTransform(-(Single)b.Width / 2, -(Single)b.Height / 2);
			// Draw passed in image onto graphics object
			g.DrawImage(b, srect, srect, GraphicsUnit.Pixel);
			return returnBitmap;
		}
	}
}