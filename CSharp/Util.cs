using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace export
{
    class Util
    {
        public static DateTime FromIsoDate(string datetime)
        {
            return DateTime.Parse(datetime, null, DateTimeStyles.RoundtripKind);
        }

        public static string ToIsoDate(DateTime date)
        {
            return date.ToString("yyyy-MM-ddTHH:mm:ssZ");
        }
    }
}
