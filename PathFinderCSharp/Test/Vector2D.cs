using System;

namespace Test
{
    public class Vector2D
    {
        public double X { get; set; }
        public double Y { get; set; }
        public Vector2D()
        {
            this.X = 0.0;
            this.Y = 0.0;
        }
        public Vector2D(double x, double y)
        {
            this.X = x;
            this.Y = y;
        }
        public void setZero()
        {
            X = 0.0;
            Y = 0.0;
        }

        public bool isZero()
        {
            return X == 0 && Y == 0;
        }

        public double Length()
        {
            return Math.Sqrt(X * X + Y * Y);
        }

        double LengthSquared()
        {
            return X * X + Y * Y;
        }

        public void Normalize()
        {
            double length = Length();
            X /= length;
            Y /= length;
        }

        public double Dot(Vector2D otherVector)
        {
            return X * otherVector.X + Y * otherVector.Y;
        }

        public double DistanceTo(Vector2D otherVector)
        {
            double XDistance = otherVector.X - X;
            double YDistance = otherVector.Y - Y;
            return Math.Sqrt(XDistance * XDistance + YDistance * YDistance);
        }

        public double DistanceToSquared(Vector2D otherVector)
        {
            double XDistance = otherVector.X - X;
            double YDistance = otherVector.Y - Y;
            return XDistance * XDistance + YDistance * YDistance;
        }

        public static Vector2D operator+(Vector2D vector,Vector2D otherVector)
        {
            var tempVector = new Vector2D(vector.X, vector.Y);
            tempVector.X += otherVector.X;
            tempVector.Y += otherVector.Y;
            return tempVector;
        }

        public static Vector2D operator-(Vector2D vector, Vector2D otherVector)
        {
            var tempVector = new Vector2D(vector.X, vector.Y);
            tempVector.X -= otherVector.X;
            tempVector.Y -= otherVector.Y;
            return tempVector;
        }

        public static Vector2D operator*(Vector2D vector, double multiplier)
        {
            var tempVector = new Vector2D(vector.X, vector.Y);
            tempVector.X *= multiplier;
            tempVector.Y *= multiplier;
            return tempVector;
        }

        public static Vector2D operator/ (Vector2D vector,double dividend)
        {
            var tempVector = new Vector2D(vector.X, vector.Y);
            tempVector.X /= dividend;
            tempVector.Y /= dividend;
            return tempVector;
        }

        public static bool operator ==(Vector2D vector1, Vector2D vector2)
        {
            if (ReferenceEquals(vector1, vector2))
            {
                return true;
            }
            if ((object)vector1 == null || (object)vector2 == null)
            {
                return false;
            }
            return (vector1.X == vector2.X && vector1.Y == vector2.Y);
        }

        public static bool operator !=(Vector2D vector1,Vector2D vector2)
        {
            return (vector1.X != vector2.X) || (vector1.Y != vector2.Y);
        }

        public override bool Equals(object obj)
        {
            if (obj == null) return false;
            var otherVector = (Vector2D)obj;

            return (object)otherVector != null && this.X == otherVector.X && this.Y == otherVector.Y;
        }

        public  bool Equals(Vector2D otherVector)
        {
            return (object)otherVector != null && this.X == otherVector.X && this.Y == otherVector.Y;
        }

        public override int GetHashCode()
        {
            return (this.X.GetHashCode() * 7) + (this.Y.GetHashCode() * 7 * 2);
        }
    }
}

