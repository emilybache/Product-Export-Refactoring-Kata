import { format, parseISO } from 'date-fns-tz';

export class Util {

    static fromIsoDate(dateTime: string): Date {
        // TimeZone tz = TimeZone.getTimeZone("UTC");
        // DateFormat df = new SimpleDateFormat("yyyy-MM-dd'T'HH:mm'Z'");
        // df.setTimeZone(tz);
        // return df.parse(datetime);
        return parseISO(dateTime);
    }

    static toIsoDate(date: Date): string {
        // TimeZone tz = TimeZone.getTimeZone("UTC");
        // DateFormat df = new SimpleDateFormat("yyyy-MM-dd'T'HH:mm'Z'");
        // df.setTimeZone(tz);
        // return df.format(date);
        return format(date, "yyyy-MM-dd'T'HH:mm'Z'", { timeZone: 'UTC' });
    }

}
