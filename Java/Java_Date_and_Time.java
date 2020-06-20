

class Result {

    /*
     * Complete the 'findDay' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts following parameters:
     *  1. INTEGER month
     *  2. INTEGER day
     *  3. INTEGER year
     */


    // Resource: https://docs.oracle.com/javase/7/docs/api/java/util/Date.html#getDay()

    public static String findDay(int month, int day, int year) {

        // Parameters: Date(int year, int month, int date)
        // year - the year minus 1900
        // month - the month between 0-11
        // date - the day of the month between 1-31
        Date myDay = new Date(year-1900, month-1, day);

        String dayOfWeek = "";

        // Return values of getDay():
        // 0 = Sunday, 1 = Monday,..., 6 = Saturday
        switch(myDay.getDay())
        {
            case 0: dayOfWeek = "SUNDAY";
            break;

            case 1: dayOfWeek = "MONDAY";
            break;

            case 2: dayOfWeek = "TUESDAY";
            break;

            case 3: dayOfWeek = "WEDNESDAY";
            break;

            case 4: dayOfWeek = "THURSDAY";
            break;

            case 5: dayOfWeek = "FRIDAY";
            break;

            case 6: dayOfWeek = "SATURDAY";
            break;
        }

        return dayOfWeek;
    }
}

